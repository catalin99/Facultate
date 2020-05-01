package Server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.Scanner;

public class GameServer {
    private static final int PORT = 8100;
    private ServerSocket serverSocket;
    private boolean running = false;

    public static void main(String[] args)  {
        GameServer server = new GameServer();
        server.init();
        server.waitForClients(); //... handle the exceptions!
    }
    private void init() {
        try {
            serverSocket = new ServerSocket( PORT );
        } catch (IOException e) {
            e.printStackTrace();
        }
        running = true;
    }
    // Implement the init() method: create the serverSocket and set running to true
    private void waitForClients(){
        while( running ) {
            System.out.println(" Asteptam un client... ");
            try {
                Socket socket = serverSocket.accept();
                new ClientThread(socket,this).start();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    // Implement the waitForClients() method: while running is true, create a new socket for every incoming client and start a ClientThread to execute its request.

    public void stop() throws IOException {
        this.running = false;
        serverSocket.close();
    }

    private String readFromKeyboard() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }
}
