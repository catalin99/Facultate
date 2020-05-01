package server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class SocialNetworkServer {
    private static final int PORT = 8100;
    private ServerSocket serverSocket;
    private boolean running = false;

    private SocialNetwork socialNetwork = new SocialNetwork();

    public static void main(String[] args) {
        // write your code here
        SocialNetworkServer server = new SocialNetworkServer();
        try {
        server.init();
        server.waitForClients();

        }catch (IOException e){
            System.out.println("[server] Server has stopped");
        }
    }

    public void init() throws IOException {
        serverSocket = new ServerSocket(PORT);
        running = true;
        System.out.println("[server] Server is running on port " + PORT);
    }

    public void waitForClients() throws IOException {
        while (running) {
            System.out.println("[server] Waiting for a client ...");
            Socket socket = serverSocket.accept();
            System.out.println("[server] New connection from " + socket.toString());
            new ClientThread(this, socket).start();
        }
    }

    public void stop() {
        try {
            this.running = false;
            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public boolean isRunning() {
        return running;
    }

    public synchronized SocialNetwork getSocialNetwork() {
        return socialNetwork;
    }
}
