package DocumentManagementSystem;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        String commandLine;
        BufferedReader console = new BufferedReader(new InputStreamReader(System.in));

        //Break with Ctrl+C
        while (true) {
            //read the command
            System.out.print("shell > ");
            commandLine = console.readLine();

            //if just a return, loop
            if (commandLine.equals(""))
                continue;

            // create new Catalog
            if (commandLine.matches("(new).[A-Za-z]*")) {
                String[] values = commandLine.split(" ");
                Catalog catalog = new Catalog();
                continue;
            }

            // add to catalog
            if (commandLine.matches("(add)\\s(book).*")) {
                if(commandLine.matches("(add)\\s(book)(\\s\"[^\"]*\"){2}\\s(\\d){4}(\\s\"[^\"]*\")*")) {
                    new AddCommand("book");
                    String[] values = commandLine.split("( \\\")|(\\\" )(?=\\d)|(\\\" \\\")|(\\\")");
                    for(String i : values)
                        System.out.println(i);
                }
                else {
                    System.out.println("Formatul nu este corect: add book \"Titlu\" \"Path\" An \"Autori\"");
                }
                continue;
            }

            //help command
            if (commandLine.equals("help")) {
                Command.generalHelp();
                continue;
            }

            if (commandLine.equals("clear")) {
                for ( int cls = 0; cls< 10; cls++ ) {
                    System.out.println();
                }
                continue;
            }

            if (commandLine.endsWith(".java")) {
                if (commandLine.startsWith("cat")) {
                    System.out.println("merge");
                    ProcessBuilder pb = new ProcessBuilder();
                    pb = new ProcessBuilder(commandLine);
                } else {
                    System.out.println("Incorrect Command");
                }
                continue;
            }

            if (commandLine.equals("exit")) {
                System.out.println(".\n..\n...\nGood bye!");
                System.exit(0);
                continue;
            }

            System.out.println("Commanda nu exista !");
        }


//        try {
//            Catalog catalog = new Catalog();
//            catalog.add(new Book("The Art of Computer Programming", "D:\\Workspace\\Windows\\Desktop\\Projects\\PA\\Laborator\\lab4\\resources\\book.txt", 1967, "Donald E. Knuth"));
//            catalog.add(new Article("Mastering the Game of Go without Human Knowledge", "D:\\Workspace\\Windows\\Desktop\\Projects\\PA\\Laborator\\lab4\\resources\\article.txt", 2017, "David Silver", "Julian Schrittwieser", "Karen Simonyan"));
//            catalog.save("D:\\Workspace\\Windows\\Desktop\\Projects\\PA\\Laborator\\lab4\\resources\\catalog.dat");
//            catalog.list();
//            Catalog catalog1 = new Catalog();
//            catalog1.list();
//            catalog1.load("D:\\Workspace\\Windows\\Desktop\\Projects\\PA\\Laborator\\lab4\\resources\\catalog.dat");
//            catalog1.list();
//            catalog.open(1);
//        } catch ( FileNotFoundException e ) {
//            e.printStackTrace();
//        } catch (Document.YearException e) {
//            e.printStackTrace();
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
    }
}
