package ru.nsu.ccfit.lukin.web.sockets;

import java.io.*;
import java.net.*;

public class TCPSocket extends SocketImpl {
    DatagramSocket socket;
    ByteArrayOutputStream baout;
    ByteArrayInputStream bain;
    @Override
    protected void create(boolean stream) throws IOException {

    }

    @Override
    protected void connect(String host, int port) throws IOException {
        connect(new InetSocketAddress(host, port), port);
    }

    @Override
    protected void connect(InetAddress address, int port) throws IOException {
        connect(new InetSocketAddress(address, port), 0);
    }

    @Override
    protected void connect(SocketAddress address, int timeout) throws IOException {
        socket.connect(address);
    }

    @Override
    protected void bind(InetAddress host, int port) throws IOException {
        socket.bind(new InetSocketAddress(host, port));
    }

    @Override
    protected void listen(int backlog) throws IOException {

    }

    @Override
    protected void accept(SocketImpl s) throws IOException {

    }

    @Override
    protected InputStream getInputStream() throws IOException {
        return null;
    }

    @Override
    protected OutputStream getOutputStream() throws IOException {
        return null;
    }

    @Override
    protected int available() throws IOException {
        return 0;
    }

    @Override
    protected void close() throws IOException {

    }

    @Override
    protected void sendUrgentData(int data) throws IOException {

    }

    @Override
    public void setOption(int optID, Object value) throws SocketException {

    }

    @Override
    public Object getOption(int optID) throws SocketException {
        return null;
    }
}
