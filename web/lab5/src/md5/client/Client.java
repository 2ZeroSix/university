package md5.client;

import md5.general.Info;
import md5.general.MessageType;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.UUID;

import static java.lang.Thread.sleep;

public class Client {
    public static final int SLEEP_TIME = 5000;
    public static final UUID uuid = UUID.randomUUID();
    public static final byte[] uuidInBytes = uuid.toString().getBytes();
    public static String md5 = null;
    public static int startValue;
    public static int endValue;
    public static boolean weFound = false;
    public static final int MAX_ATTEMPTS_TO_CONNECT = 10;

    public static StringBuffer tmpMd5 = new StringBuffer("");

    public static void main(String[] args) {

        boolean itIsFirstConnection = true;
        boolean goOrNo = true;
        int md5Length = countMd5Length();
        if (md5Length == -1){
            System.out.println("some problems with counting md5Length");
            return;
        }
        int countAttempts = 0;
        try {
            while (true) {
                if (countAttempts == MAX_ATTEMPTS_TO_CONNECT){
                    System.out.println("we have tried to connect " + MAX_ATTEMPTS_TO_CONNECT + " times");
                    return;
                }
                try (Socket socket = new Socket(InetAddress.getByName(Info.SERVER_IP_STRING), Info.SERVER_PORT);
                     InputStream inputStream = socket.getInputStream();
                     OutputStream outputStream = socket.getOutputStream()) {
                    if (itIsFirstConnection) {
                        goOrNo = handleFirstConnection(inputStream, outputStream, md5Length);
                        itIsFirstConnection = false;
                    } else {
                        goOrNo = handleNotFirstConnection(inputStream, outputStream);
                    }
                    countAttempts = 0;
                } catch (UnknownHostException e) {
                    System.out.println("unknown host exception WTF");
                    return;
                } catch (IOException e) {
                    System.out.println(e.getLocalizedMessage());
                    itIsFirstConnection = true;
                    countAttempts++;
                }

                if (weFound)
                    break;
                if (goOrNo) {
                    String ourMd5 = tryingToFindString();
                    if (ourMd5 != null){
                        System.out.println("CHECK THIS: ");
                        System.out.println(ourMd5);
                    }
                }


                try {
                    System.out.println("sleep some and will try to connect again");
                    sleep(SLEEP_TIME);
                } catch (InterruptedException e) {
                    System.out.println("LOL check it: " + e.getLocalizedMessage());
                }
                goOrNo = true;
            }
        }catch(NotContinueException e){
            System.out.println(e.getErrorMessage());
        }
    }

    /*
    * -> uuid
    * -> first connection byte
    * ------------
    * <- OK or NOT_OK byte
    * <- int start
    * <- int end
    * <- md5
    * -> OK or NOT_OK byte
    * */
    private static boolean handleFirstConnection(InputStream is, OutputStream os, int md5Length) throws IOException{
        byte[] startAndEnd = new byte[8];
        os.write(uuidInBytes, 0, uuidInBytes.length);
        os.write(MessageType.FIRST_CONNECT);
        if (is.read() != MessageType.OK) {
            return false;
        }
        for (int i = 0; i < 8; ++i) {
            startAndEnd[i] = (byte)is.read();
        }
        int start = getStartFromBytes(startAndEnd);
        int end   = getEndFromBytes(startAndEnd);

        byte[] md5InBytes = new byte[md5Length];
        int count = 0;
        while (count != md5Length){
            count += is.read(md5InBytes, count, md5Length - count);
        }
        md5 = new String(md5InBytes, 0, md5Length);
        os.write(MessageType.OK);
        startValue = start;
        endValue   = end;
        return true;
    }

    /*
    * -> uuid
    * -> notFirst connection byte
    * -------------
    * <- OK or NOT_OK byte   --- for example: if time is over
    * -> FOUND or NOT_FOUND byte
    * <- CONTINUE or NOT_CONTINUE byte
    * <- int start
    * <- int end
    * -> OK or NOT_OK byte
    * */
    private static boolean handleNotFirstConnection(InputStream is, OutputStream os) throws IOException, NotContinueException{
        byte[] startAndEnd = new byte[8];

        os.write(uuidInBytes, 0, uuidInBytes.length);
        os.write(MessageType.NOT_FIRST_CONNECT);
        if (is.read() != MessageType.OK) {
            return false;
        }

        if (weFound){
            os.write(MessageType.FOUND);
            return false;
        }
        os.write(MessageType.NOT_FOUND);
        byte tmpByte;
        if ((tmpByte = (byte)is.read()) == MessageType.NOT_CONTINUE){
            return false;
        }
        else if (tmpByte == MessageType.NEVER_CONTINUE){
            throw new NotContinueException("server said bb");
        }


        for (int i = 0; i < 8; ++i) {
            startAndEnd[i] = (byte)is.read();
        }
        int start = getStartFromBytes(startAndEnd);
        int end   = getEndFromBytes(startAndEnd);

        os.write(MessageType.OK);
        startValue = start;
        endValue   = end;
        return true;
    }

    public static int getStartFromBytes(byte[] buf){
        int tmp = 0;
        for (int i = 0; i < 4; ++i){
            tmp = tmp << 8;
            tmp = tmp | ((int)(buf[i]) & 0xff);
        }
        return tmp;
    }

    public static int getEndFromBytes(byte[] buf){
        int tmp = 0;
        for (int i = 4; i < 8; ++i){
            tmp = tmp << 8;
            tmp = tmp | ((int)(buf[i]) & 0xff);
        }
        return tmp;
    }

    public static String tryingToFindString(){
        int tmpInt = startValue;
        StringBuffer  tmp = new StringBuffer("");
        while (tmpInt >= Info.ALPHABET.length){
            tmp.append(Info.ALPHABET[tmpInt % Info.ALPHABET.length]);
            tmpInt = tmpInt / Info.ALPHABET.length;
        }
        tmp.append(Info.ALPHABET[tmpInt]);
        tmp.reverse();
        System.out.println("WE ARE STARTING WITH: " + tmp.toString());

        int count = 0;
        for(int i = 0; i < endValue - startValue; ++i){
            count++;
            if (count == 500) {
                System.out.println("Current string: ");
                System.out.println(tmp.toString());
            }


            if (checkThisString(tmp)){
                weFound = true;
                return tmp.toString();
            }
            getNewString(tmp);
        }
        return null;
    }

    private static void getNewString(StringBuffer stringBuffer){
        for (int i = stringBuffer.length() - 1; i >= 0; --i){
            if (stringBuffer.charAt(i) != Info.ALPHABET[Info.ALPHABET.length - 1]){
                for (int j = 0; j < Info.ALPHABET.length; ++j){
                    if (stringBuffer.charAt(i) == Info.ALPHABET[j]){
                        stringBuffer.replace(i, i + 1, String.valueOf(Info.ALPHABET[j + 1]));
                        break;
                    }
                }
                break;
            }
            else{
                stringBuffer.replace(i, i + 1, String.valueOf(Info.ALPHABET[0]));
                if (i == 0){
                    stringBuffer.insert(0, String.valueOf(Info.ALPHABET[0]));
                }
            }
        }
    }



    private static boolean  checkThisString(StringBuffer stringBuffer){
        StringBuffer sb;
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            md.update(stringBuffer.toString().getBytes());
            byte[] digest = md.digest();
            sb = new StringBuffer();
            for (byte b : digest) {
                sb.append(String.format("%02x", b & 0xff));
            }
            if (sb.toString().equals(md5)){
                return true;
            }
            else{
                return false;
            }

        }catch(NoSuchAlgorithmException e){
            return false;
        }
    }

    public static int countMd5Length(){
        String target = "AAA";
        StringBuffer sb;
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            md.update(target.getBytes());
            byte[] digest = md.digest();
            sb = new StringBuffer();
            for (byte b : digest) {
                sb.append(String.format("%02x", b & 0xff));
            }
            return sb.toString().length();
        }catch(NoSuchAlgorithmException e){
            return -1;
        }
    }

}
