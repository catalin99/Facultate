import com.sun.javafx.scene.traversal.SubSceneTraversalEngine;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

public class SocialNetworkServer {
    private static final int PORT = 7100;
    private ServerSocket serverSocket;
    private boolean running = false;

    public static void main(String[] args) throws IOException {
        SocialNetworkServer server = new SocialNetworkServer();
        server.init();
        server.waitForClients();

    }

    public void init() throws IOException {
        serverSocket = new ServerSocket(PORT);
        running = true;
        System.out.println("[server] Server is running on port " + PORT);
    }

    public void waitForClients() throws IOException {
        try {
            while (running) {
                System.out.println("[server] Waiting for a client ...");
                Socket socket = serverSocket.accept();
                System.out.println("[server] New connection from " + socket.toString());
                new ClientThread(this, socket).start();
            }
        }
        catch (SocketException e)
        {
            System.out.println("Server is not running anymore");
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
}