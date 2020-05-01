import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.util.ArrayList;
import java.util.List;


public class ClientThread extends Thread {
        private static final int TIMEOUT_MINUTES = 1;
        private static final int READ_TIMEOUT = 60 * 1000 * TIMEOUT_MINUTES;
        private Socket clientSocket = null;
        private final SocialNetworkServer server;

        ClientThread(SocialNetworkServer server, Socket clientSocket) {
            this.server = server;
            this.clientSocket = clientSocket;
        }

        public void run() {
            try {
                // daca nu primim mesaj timp de TIMEOUT_MINUTES sec de la client, inchidem conexiunea
                clientSocket.setSoTimeout(READ_TIMEOUT);
                BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
                SocialNetwork socialNetwork=new SocialNetwork();
                while (server.isRunning()) {

                    String request = in.readLine();
                    System.out.println("[thread] New message '" + request + "' from " + clientSocket);
                    if(request.equals("exit"))
                        break;
                    else if(request.equals("stop"))
                    {
                        String response = "[thread]Server stopped";
                        System.out.println(response);
                        server.stop();
                        break;
                    }
                    else if(request.contains("register"))
                    {
                        System.out.print(socialNetwork.Register(request.substring(request.indexOf(' ')+1)));
                    }
                    else if(request.contains("login"))
                    {
                        System.out.print(socialNetwork.Login(request.substring(request.indexOf(' ')+1)));
                    }
                    else if(request.contains("friend"))
                    {
                        String[] splitedString=request.split(" ");
                        String name=splitedString[1];
                        List<String> friends=new ArrayList<>();
                        for(int i=2; i<splitedString.length; i++)
                            friends.add(splitedString[i]);
                        System.out.print(socialNetwork.addFriends(name, friends));

                    }
                    else if(request.contains("message"))
                    {
                        String[] splitedString=request.split(" ");
                        String name=splitedString[1];
                        String messages=new String();
                        for(int i=2; i<splitedString.length; i++)
                        {
                            messages+=splitedString[i];
                            messages+=" ";
                        }
                        System.out.print(socialNetwork.send(name, messages));
                    }
                    else if(request.contains("read"))
                    {
                        System.out.print(socialNetwork.read(request.substring(request.indexOf(' ')+1)));
                    }
                    String response = null;
                    System.out.println("[thread] Sending message to client");
                    out.println(response);
                }

            } catch (SocketTimeoutException e) {
                System.out.println("[thread] Timeout reached! Closing connection with " + clientSocket);

            } catch (IOException e) {
                //e.printStackTrace();
                System.out.println("[thread] Closing connection with " + clientSocket);
            }
            finally
            {
                try {
                    clientSocket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

}
