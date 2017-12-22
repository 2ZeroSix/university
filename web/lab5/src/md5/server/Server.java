package md5.server;

import md5.general.Info;
import md5.general.MessageType;
import md5.general.TaskTypeInArray;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.UUID;


public class Server extends Thread{
    private static String key = "CACGTATCAD";
    private static int port = Info.SERVER_PORT;
    private static String md5;

    private static Set<ClientInfo> uuidSet = new HashSet<>();
    private static byte[] taskArray = new byte[Info.MAX_LENGTH / Info.STEP + 1];
    private static int indexOfFreeTask = 0;
    private static boolean runOutOfTasksOrKeyWasFound = false;

    private Socket clSocket;
    private ClientInfo tempClient;

    public static void main(String[] args) {
        for (int i = 0; i < taskArray.length; ++i){
            taskArray[i] = TaskTypeInArray.READY;
        }

        md5 = getMd5FromKey(key);
        if (md5 == null){
            System.out.println("md5 is null:(");
            return;
        }

        Thread cleaner = new Thread(){
            @Override
            public void run() {
                cleanerBody();
            }
        };
        cleaner.start();

        Server tmpThread = null;
        try(ServerSocket serverSocket = new ServerSocket(port)) {
            serverSocket.setSoTimeout(Info.MAX_TIME_FOR_TASK);
            while(true) {
                try {
                    tmpThread = new Server(serverSocket.accept());
                    tmpThread.start();
                } catch (SocketTimeoutException e) {
                    System.out.println("We have not had a connection for " + Info.MAX_TIME_FOR_TASK / 1000 + " secs");
                }

                if (runOutOfTasksOrKeyWasFound){
                    boolean weNeedToWait = false;
                    synchronized (uuidSet) {
                        if (!uuidSet.isEmpty()) {
                            weNeedToWait = true;
                        }
                    }
                    if (weNeedToWait) {
                        try {
                            sleep(Info.MAX_TIME_FOR_TASK);
                        } catch (InterruptedException e) {

                        }
                    }
                    System.out.println("Server is out");
                    break;
                }
            }
            serverSocket.close();
            cleaner.interrupt();

        }
        catch(IOException e){
            System.out.println(e.getLocalizedMessage());
            return;
        }
        
    }
    
    private Server(Socket socket){
        this.clSocket = socket;
        this.tempClient = new ClientInfo(null, -1, -1);
    }

    @Override
    public void run() {

        try(InputStream inputStream = clSocket.getInputStream();
            OutputStream outputStream = clSocket.getOutputStream()){

            //read uuid
            byte[] buf = new byte[Info.UUID_LENGTH];
            int count = 0;
            while(count != Info.UUID_LENGTH){
                count += inputStream.read(buf, count, Info.UUID_LENGTH - count);
            }
            UUID uuid = UUID.fromString(new String(buf, 0, count));

            boolean flag = false;
            buf[0] = (byte)inputStream.read();
            if (buf[0] == MessageType.FIRST_CONNECT){
                flag = handleFirstConnection(inputStream, outputStream, uuid);
            }
            else{
                flag = handleNotFirstConnection(inputStream, outputStream, uuid);
            }

            if (flag){
                System.out.println("new client is a good boy");
            }
            else{
                System.out.println("new client is a bad boy");
            }
        } catch(IOException ignored){

        } catch (IllegalArgumentException ignored) {

        } finally {
            try{
                clSocket.close();
            }
            catch(IOException e){
                System.out.println("Cant close the socket. WTF");
            }
        }

    }

    /*
    * <- uuid
    * <- first connection byte
    * ------------
    * -> OK or NOT_OK byte
    * -> int start
    * -> int end
    * -> md5
    * <- OK or NOT_OK byte
    * */
    private boolean handleFirstConnection(InputStream is, OutputStream os, UUID uuid) throws IOException{
        byte[] start;
        byte[] end;
        int index = -1;
        boolean weOk = true;
        synchronized (taskArray){
            if (taskArray.length == indexOfFreeTask || runOutOfTasksOrKeyWasFound){
                os.write(MessageType.NOT_OK);
                return false;
            }
            index = indexOfFreeTask;
            taskArray[indexOfFreeTask] = TaskTypeInArray.IN_PROCESS;
            updateTaskIndex(indexOfFreeTask);
        }
        try {
            start = getBytesFromInt(index * Info.STEP);
            end   = getBytesFromInt(index * Info.STEP + Info.STEP - 1);
            os.write(MessageType.OK);
            os.write(start, 0, start.length);
            os.write(end, 0, end.length);
            os.write(md5.getBytes(), 0, md5.getBytes().length);
            if (is.read() != MessageType.OK) {
                weOk = false;
            } else{
                synchronized (uuidSet){
                    uuidSet.add(new ClientInfo(uuid, index, index));
                    uuidSet.notify();
                }
            }
        }
        catch (IOException e){
            weOk = false;
        }
        finally {
            if (index == -1)
                return false;
            if (!weOk){
                synchronized (taskArray){
                    taskArray[index] = TaskTypeInArray.READY;
                    if (indexOfFreeTask > index){
                        indexOfFreeTask = index;
                    }
                }
                return false;
            }
            return true;
        }
    }

    /*
    * <- uuid
    * <- notFirst connection byte
    * -------------
    * -> OK or NOT_OK byte   --- for example: if time is over
    * <- FOUND or NOT_FOUND byte
    * -> CONTINUE or NOT_CONTINUE byte
    * -> int start
    * -> int end
    * <- OK or NOT_OK byte
    * */
    private boolean handleNotFirstConnection(InputStream is, OutputStream os, UUID uuid) throws  IOException{
        boolean weOk = true;
        int index = -1;
        try{
            int startIndex = -1;
            int endIndex   = -1;
            synchronized (uuidSet){//check if our set contains his uuid
                tempClient.setUuid(uuid);
                if(!uuidSet.contains(tempClient)){
                    os.write(MessageType.NOT_OK);
                } else {
                    for (ClientInfo clientInfo : uuidSet){
                        if (clientInfo.getUuid().equals(uuid)){
                            startIndex = clientInfo.getStartTaskIndex();
                            endIndex   = clientInfo.getFinalTaskIndex();
                        }
                    }
                    uuidSet.remove(tempClient);
                    os.write(MessageType.OK);
                }
            }
            synchronized (taskArray){
                for (int i = startIndex; i <= endIndex; ++i){
                    taskArray[startIndex] = TaskTypeInArray.DONE;
                }
                if (indexOfFreeTask == taskArray.length){
                    if (checkIfAllTasksIsDone()){
                        runOutOfTasksOrKeyWasFound = true;
                    }
                    weOk = false;
                }
            }
            if (is.read() == MessageType.FOUND){
                System.out.println("ONE OF OUR CLIENT HAS FOUND THE KEY");
                runOutOfTasksOrKeyWasFound = true;
                weOk = false;
                return true;
            }
            synchronized (taskArray){
                if (indexOfFreeTask == taskArray.length || runOutOfTasksOrKeyWasFound){
                    if (runOutOfTasksOrKeyWasFound){
                        os.write(MessageType.NEVER_CONTINUE);
                    }else {
                        os.write(MessageType.NOT_CONTINUE);
                    }
                    weOk = false;
                    return false;
                }
                index = indexOfFreeTask;
                taskArray[index] = TaskTypeInArray.IN_PROCESS;
                updateTaskIndex(indexOfFreeTask);
            }
            byte[] start = getBytesFromInt(index * Info.STEP);
            byte[] end   = getBytesFromInt(index * Info.STEP + Info.STEP - 1);
            os.write(MessageType.CONTINUE);
            os.write(start, 0, start.length);
            os.write(end,   0,   end.length);
            if (is.read() != MessageType.OK){
                weOk = false;
            }
            else {
                synchronized (uuidSet){
                    uuidSet.add(new ClientInfo(uuid, index, index));
                    uuidSet.notify();
                }
            }
        }
        catch (IOException e){
            weOk = false;
        }
        finally {
            if (index == -1)
                return false;
            if (!weOk){
                synchronized (taskArray){
                    taskArray[index] = TaskTypeInArray.READY;
                    if (indexOfFreeTask > index){
                        indexOfFreeTask = index;
                    }
                }
                return false;
            }
            return true;
        }
    }

    private boolean checkIfAllTasksIsDone(){
        for (int i = 0; i < taskArray.length; ++i){
            if (taskArray[i] != TaskTypeInArray.DONE)
                return false;
        }
        return true;
    }

    private byte[] getBytesFromInt(int number){
        byte[] tmp = new byte[4];
        for (int i = 0; i < 4; ++i){
            tmp[3 - i] = (byte)(number >> 8 * i);
        }
        return tmp;
    }

    private static void cleanerBody(){
        try {
            while (true) {
                sleep(Info.MAX_TIME_FOR_TASK);
                synchronized (uuidSet) {
                    while (uuidSet.isEmpty()) {
                        uuidSet.wait();
                    }
                    for (Iterator<ClientInfo> i = uuidSet.iterator(); i.hasNext();) {
                        ClientInfo info = i.next();
                        if (System.currentTimeMillis() - info.getStartTime() >= Info.MAX_TIME_FOR_TASK) {
                            synchronized (taskArray){
                                for (int j = info.getStartTaskIndex(); j <= info.getFinalTaskIndex(); ++j){
                                    taskArray[j] = TaskTypeInArray.READY;
                                }
                                if (indexOfFreeTask > info.getStartTaskIndex()){
                                    indexOfFreeTask = info.getStartTaskIndex();
                                }
                            }
                            i.remove();
                        }
                    }
                }
            }
        }
        catch (InterruptedException e) {
            System.out.println("interrupt from cleaner");

        }

    }

    private static String getMd5FromKey(String target){
        StringBuffer sb;
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            md.update(target.getBytes());
            byte[] digest = md.digest();
            sb = new StringBuffer();
            for (byte b : digest) {
                sb.append(String.format("%02x", b & 0xff));
            }
            return sb.toString();
        }catch(NoSuchAlgorithmException e){
            return null;
        }

    }

    private static void updateTaskIndex(int lastIndex){
        boolean weFound = false;
        for (int i = lastIndex + 1; i < taskArray.length; ++i){
            if (taskArray[i] == TaskTypeInArray.READY){
                indexOfFreeTask = i;
                weFound = true;
                break;
            }
        }
        if (!weFound){
            indexOfFreeTask = taskArray.length;
        }
    }
}
