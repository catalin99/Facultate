package server;

import java.io.*;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.Arrays;

public class ClientThread extends Thread {
    private static final int READ_TIMEOUT = 10 * 1000;
    private Socket clientSocket;
    private final SocialNetworkServer server;
    private String clientName;

    ClientThread(SocialNetworkServer server, Socket clientSocket) {
        this.server = server;
        this.clientSocket = clientSocket;
    }

    public void run() {
        try {
            // daca nu primim mesaj timp de 10 sec de la client, inchidem conexiunea
            clientSocket.setSoTimeout(READ_TIMEOUT);
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

            while (server.isRunning()) {
                String request = in.readLine();
                System.out.println("[thread] New message '" + request + "' from " + clientSocket);

                String response = execute(request);
                System.out.println("[thread] Sending message to client");
                out.println(response);
            }

        } catch (SocketTimeoutException e) {
            System.out.println("[thread] Timeout reached! Closing connection with " + clientSocket);

        } catch (IOException e) {
            //e.printStackTrace();
            System.out.println("[thread] Closing connection with " + clientSocket);
        } finally {
            try {
                clientSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private String execute(String request) {
        if (clientName == null) {
            if (request.startsWith("login ")) {
                String name = request.substring(6);
                String response = server.getSocialNetwork().login(name);

                if (!response.startsWith("Error!"))
                    clientName = name;

                return response;
            }

            if (request.startsWith("register ")) {
                String name = request.substring(9);
                return server.getSocialNetwork().register(name);
            }
        }

        if (clientName != null) {
            if (request.startsWith("friend ")) {
                String[] friendList = request.substring(7).split(" ");
                return server.getSocialNetwork().addFriends(clientName, Arrays.asList(friendList));
            }

            if (request.startsWith("send ")) {
                String message = request.substring(5);
                return server.getSocialNetwork().send(clientName, message);
            }

            if (request.startsWith("read")) {
                return server.getSocialNetwork().read(clientName);
            }

            if (request.startsWith("stop")) {
                server.stop();
                return "Server has stopped";
            }
        }

        return "Error! Invalid command!";
    }
}
