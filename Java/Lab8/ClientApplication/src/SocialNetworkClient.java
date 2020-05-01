import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class SocialNetworkClient {
    private final static String SERVER_ADDRESS = "127.0.0.1";
    private final static int PORT = 7100;
    private Socket socket;

    SocialNetworkClient() throws IOException {
        socket = new Socket(SERVER_ADDRESS, PORT);
    }

    public static void main(String[] args) {
        try {
            SocialNetworkClient client = new SocialNetworkClient();
            while (true) {
                String request = client.readFromKeyboard();

                if (request.equalsIgnoreCase("exit"))
                    break;

                client.sendRequestToServer(request);

                if(request.equals("stop"))
                    break;
            }
        }
        catch (IOException e) {
            System.out.println("Closing connection with the server");
        }
    }

    private String readFromKeyboard() {
        Scanner in = new Scanner(System.in);
        return in.nextLine();
    }

    private void sendRequestToServer(String request) throws IOException {
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        out.println(request);

        String response = in.readLine();
//        System.out.println(response);
    }
}