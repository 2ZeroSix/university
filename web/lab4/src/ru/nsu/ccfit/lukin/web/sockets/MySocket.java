package ru.nsu.ccfit.lukin.web.sockets;

import java.io.IOException;
import java.net.*;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.TimeUnit;

public class MySocket {

    enum State { CLOSED, ESTABLISHED, FIN }

    final static byte SYN_FLAG = 1;
    final static byte ACK_FLAG = 2;
    final static byte FIN_FLAG = 4;
    final static byte RST_FLAG = 8;

    final static short HEADER_SIZE = 9;
    final static short MAX_PACKET_SIZE = 1024;
    final static short MAX_DATA_SIZE = MAX_PACKET_SIZE - HEADER_SIZE;

    private ConcurrentHashMap<Integer, DatagramPacket> outPackets = new ConcurrentHashMap<>();
    private BlockingQueue<DatagramPacket> acks = new LinkedBlockingDeque<>();
    private ConcurrentHashMap<Integer, DatagramPacket> unexpectedPackets = new ConcurrentHashMap<>();
    private DatagramSocket datagramSocket = null;
    private BlockingQueue<DatagramPacket> inPackets = new LinkedBlockingDeque<>();

    private int sequenceNum = 1;
    private int expectedSeqNum;

    private int destinationPort;
    private InetAddress destinationAddress;

    private State state = State.CLOSED;

    private Thread sender;
    private Thread receiver;

    private final Object obj = new Object();

    private byte[] outData;

    MySocket(InetAddress host, int port, int clientSeq) {
        destinationAddress = host;

        destinationPort = port;
        expectedSeqNum = clientSeq;
        state = State.ESTABLISHED;
    }

    private boolean connect() throws IOException {
        for (int i = 0; i < 5; i++) {
            ByteBuffer data = ByteBuffer.allocate(HEADER_SIZE);

            data.putInt(sequenceNum++);
            data.putInt(0);
            data.put(SYN_FLAG);
            data.flip();

            DatagramPacket packet = new DatagramPacket(data.array(), data.capacity(), destinationAddress, destinationPort);

            try {
                datagramSocket.send(packet); // отправляем SYN

                data.clear();

                byte[] buffer = new byte[HEADER_SIZE];

                DatagramPacket receivedPacket = new DatagramPacket(buffer, buffer.length);
                datagramSocket.receive(receivedPacket);
                data = ByteBuffer.wrap(receivedPacket.getData());
            } catch (SocketTimeoutException ex) {
                continue;
            }

            int serverSeq = data.getInt();
            int ack = data.getInt();
            byte flags = data.get();

            if ((flags & SYN_FLAG) == SYN_FLAG) {
                if (((flags & ACK_FLAG) == ACK_FLAG) && (ack == sequenceNum)) {
                    // получаем в ответ SYN ACK и отправляем свой ACK
                    sendAck(++serverSeq);
                    expectedSeqNum = serverSeq;

                    state = State.ESTABLISHED;
                    synchronized (obj) {
                        obj.notify(); // будим ресивера
                    }
                    System.out.println("Connection Established");
                    return true;
                } else {
                    throw new IOException("Received SYN, but not ACK. Or ack num wrong");
                }
            } else if ((flags & RST_FLAG) == RST_FLAG) {
                throw new IOException("RST received");
            }

            try {
                Thread.sleep(3000); // через 3 секунды пробуем коннектиться снова
//                state = State.CLOSED;
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }

        return false;
    }

    public int receive(byte[] buffer) {
        int ret = 0;

        // если есть что-то, что мы не выдали в прошлые вызовы receive
        if (outData != null) {
            int size;
            byte[] newOutData = null;
            if (outData.length > buffer.length) {
                size = buffer.length;
                newOutData = new byte[outData.length - buffer.length];
            } else {
                size = outData.length;
            }

            System.arraycopy(outData, 0, buffer, 0, size);
            ret += size;

            if (newOutData != null) {
                System.arraycopy(outData, size, newOutData, 0, newOutData.length);
                outData = newOutData;
                return ret;
            } else {
                outData = null;
            }
        }

        while (ret < buffer.length) {
            try {
                DatagramPacket packet = null;
                for (int i = 0; i < 3; i++) {
                    if (inPackets.isEmpty()) { // если очередь пустая, ищем следующий пакет в списке нежданых
                        if (unexpectedPackets.containsKey(expectedSeqNum)) {
                            addPacket(unexpectedPackets.get(expectedSeqNum));
                            unexpectedPackets.remove(expectedSeqNum);
                            incExpectedSeqNum();
                        }
                    }

                    packet = inPackets.poll(1000, TimeUnit.MILLISECONDS); // забираем пакет из очереди
                    if (packet != null) {
                        break;
                    }
                }

                if (packet == null) {
                    return ret;
                }

                ByteBuffer data = ByteBuffer.wrap(packet.getData());

                data.getInt();
                data.getInt();
                byte flags = data.get();

                if ((flags & FIN_FLAG) == FIN_FLAG) {
                    setFinState();
                    return 0;
                }

                int size = data.getInt();

                byte[] tmp = new byte[size];
                data.get(tmp);

                // если очередной пакет не влезает в буффер
                if (ret + size > buffer.length) {
                    int outSize = (ret + size) - buffer.length;
                    outData = new byte[outSize];

                    System.arraycopy(tmp, size - outSize, outData, 0, outSize);

                    System.arraycopy(tmp, 0, buffer, ret, (buffer.length - ret));
                    ret += (buffer.length - ret);
                } else {
                    System.arraycopy(tmp, 0, buffer, ret, size);
                    ret += size;
                }
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }

        return ret;
    }

    public void send(byte[] buffer) throws SocketException {
        if (state == State.FIN && outPackets.isEmpty()) {
            throw new SocketException("socket closed");
        }

        int max_size = MAX_DATA_SIZE - 4;
        int size;

        // если пакет больше, чем MAX_SIZE бьем его на куски равные MAX_SIZE
        for (int i = 0; i < buffer.length; i += max_size) {
            size = (buffer.length - i) > max_size ? max_size : (buffer.length - i);

            ByteBuffer data = ByteBuffer.allocate(MAX_PACKET_SIZE);

            data.putInt(sequenceNum++);
            data.putInt(0);
            data.put((byte) 0);

            data.putInt(size);

            byte[] tmp = new byte[size];
            System.arraycopy(buffer, i, tmp, 0, size);
            data.put(tmp);

            DatagramPacket packet = new DatagramPacket(data.array(), data.capacity(), destinationAddress, destinationPort);
            outPackets.put(sequenceNum, packet);
        }
    }

    public MySocket(String host, int port) throws SocketException {
        datagramSocket = new DatagramSocket();
        datagramSocket.setSoTimeout(1000);

        this.destinationPort = port;

        try {
            this.destinationAddress = InetAddress.getByName(host);
        } catch (UnknownHostException ex) {
            ex.printStackTrace();
        }

        // этот поток отправляет сообщения из акки из очередей для отправки
        sender = new Thread(() -> {
            // работаем, пока не нужно завершаться и пока есть, на что получить акки
            while (state != State.FIN || !outPackets.isEmpty()) {
                try {
                    ArrayList<DatagramPacket> acksForSend = getAcksForSend();

                    for (DatagramPacket packet : acksForSend) {
                        datagramSocket.send(packet);
                    }

                    ArrayList<DatagramPacket> forSend = getPacketsForSend();

                    for (DatagramPacket packet : forSend) {
                        datagramSocket.send(packet);
                    }
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        });
        sender.start();

        receiver = new Thread(() -> {
            synchronized (obj) {
                try {
                    obj.wait(); // ждем коннекта
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }

            // работаем, пока сокет не закроют, а потом пока не отправим все пакеты и не дождемся на них акков
            while (state != State.FIN || !outPackets.isEmpty() || sender.isAlive()) {
                try {
                    byte[] buffer = new byte[MAX_PACKET_SIZE];
                    DatagramPacket receivedPacket = new DatagramPacket(buffer, buffer.length);

                    datagramSocket.receive(receivedPacket);

                    ByteBuffer data = ByteBuffer.wrap(receivedPacket.getData());
                    int seq = data.getInt();
                    int ackNum = data.getInt();
                    byte flags = data.get();

                    // если получили акк, удаляем пакет, который ждал этого акка
                    if ((flags & ACK_FLAG) == ACK_FLAG) {
                        removePacket(ackNum);
                        if (seq == getExpectedSeqNum()) {
                            incExpectedSeqNum();
                        }
                        continue;
                    }

                    // если получили не тот пакет, который ждем
                    // если пакет уже получали, отправляем на него акк еще раз
                    // если этот пакет должен был прийти позже, запоминаем его
                    if (seq != expectedSeqNum) {
                        if (seq < expectedSeqNum) {
                            sendAck(++seq);
                        }
                        else {
                            addUnexpectedPacket(seq, receivedPacket);
                            sendAck(++seq);
                        }
                        continue;
                    }

                    // ждем следующий пакет
                    expectedSeqNum++;

                    // в любом другом случае отправляем акк на пришедший пакет
                    sendAck(++seq);

                    // если пришел флаг разорвать соединение, переходим в состояние завершения
                    if ((flags & RST_FLAG) == RST_FLAG) {
                        setFinState();
                        continue;
                    }

                    inPackets.add(receivedPacket);
                } catch (SocketTimeoutException ex) {
                    continue;
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        });
        receiver.start();

        // коннектимся к серверу по переданному адресу
        try {
            boolean ret = connect();
            if (!ret) {
                throw new SocketException("Не удалось установить соединение");
            }
        } catch (IOException ex) {
            System.err.println(ex.getLocalizedMessage());
        }
    }

    void sendAck(int ackNum) {
        ByteBuffer data = ByteBuffer.allocate(20);

        data.putInt(sequenceNum++);
        data.putInt(ackNum);
        data.put(ACK_FLAG);
        data.flip();

        DatagramPacket packet = new DatagramPacket(data.array(), data.capacity(), destinationAddress, destinationPort);

        acks.add(packet);
    }

    int getExpectedSeqNum() {
        return expectedSeqNum;
    }

    void incExpectedSeqNum() {
        expectedSeqNum++;
    }

    void addPacket(DatagramPacket packet) {
        inPackets.add(packet);
    }

    ArrayList<DatagramPacket> getPacketsForSend() {
        return new ArrayList<>(outPackets.values());
    }

    ArrayList<DatagramPacket> getAcksForSend() {
        ArrayList<DatagramPacket> ret = new ArrayList<>();

        acks.drainTo(ret); // забираем все из очереди и кладем в лист

        return ret;
    }

    void removePacket(int ackNum) {
        if (outPackets.containsKey(ackNum)) {
            outPackets.remove(ackNum);
        }
        // если ждем завершения работы и это был последний пакет, ожидающий акка, будим close()
        if (state == State.FIN && outPackets.isEmpty()) {
            synchronized (obj) {
                obj.notify();
            }
        }
    }

    void sendFinAck(int ackNum) {
        ByteBuffer data = ByteBuffer.allocate(HEADER_SIZE);

        data.putInt(sequenceNum++);
        data.putInt(ackNum);
        data.put((byte)(ACK_FLAG | FIN_FLAG));

        outPackets.put(sequenceNum, new DatagramPacket(data.array(), data.capacity(), destinationAddress, destinationPort));
    }

    boolean isClosed() {
        return (state == State.FIN);
    }

    private void setFinState() {
        state = State.FIN;
    }

    void addUnexpectedPacket(int seq, DatagramPacket packet) {
        unexpectedPackets.put(seq, packet);
    }
    private boolean closeClientSocket() {
        ByteBuffer data = ByteBuffer.allocate(HEADER_SIZE);

        data.putInt(sequenceNum++);
        data.putInt(0);
        data.put(RST_FLAG); // отправляем клиенту разрыв соединения

        DatagramPacket packet = new DatagramPacket(data.array(), data.capacity(), destinationAddress, destinationPort);

        outPackets.put(sequenceNum, packet);

        synchronized (obj) {
            try {
                obj.wait(1000); // даем секунду за завершение всех дел, либо пока нас не разбудят
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }

        if (!isClosed()) { // если что то не закончили, очищаем очередь сообщений для отправки, возвращаем false
            outPackets.clear();
            return false;
        }

        System.out.println("Socket closed");
        return true; // иначе все хорошо
    }
    private boolean closeServerSocket() throws IOException {
        try {
            receiver.join();
            sender.join();
        } catch (InterruptedException ex) {
            throw new IOException("interrupted");
        }

        ByteBuffer data = ByteBuffer.allocate(HEADER_SIZE);

        data.putInt(sequenceNum++);
        data.putInt(0);
        data.put(FIN_FLAG); // отправляем fin

        DatagramPacket packet = new DatagramPacket(data.array(), data.capacity(), destinationAddress, destinationPort);

        datagramSocket.send(packet);

        while (true) { // ждем акка
            byte[] buffer = new byte[HEADER_SIZE];

            DatagramPacket receivedPacket = new DatagramPacket(buffer, buffer.length);

            try {
                datagramSocket.receive(receivedPacket);

                data = ByteBuffer.wrap(receivedPacket.getData());

                int seqNum = data.getInt();
                int ack = data.getInt();
                byte flags = data.get();

                if (((flags & FIN_FLAG) == FIN_FLAG) && ((flags & ACK_FLAG) == ACK_FLAG) && (ack == sequenceNum)) {
                    // на фин акк отправляем свой акк и завершаем работу
                    sendAck(++seqNum);
                    return true;
                }
            } catch (SocketTimeoutException ex) {
                return false; // если акка не дождались
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }
    public boolean close() throws IOException {
        if (state == State.FIN) {
            return true;
        } else {
            state = State.FIN;
            if (datagramSocket == null) {
                return closeClientSocket();
            } else {
                return closeServerSocket();
            }
        }
    }
}
