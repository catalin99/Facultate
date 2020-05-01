import java.util.Scanner;

public class Problema2 {

    private static int lineCount;
    private static int[] coloane;
    static Scanner scanner;

    public static void printTable(int lineCount, int[] coloane) {
        int counter = 0;
        System.out.println("\n|");
        do {
            System.out.print("|  ");
            for (int i = 0; i < lineCount; i++)
                if (coloane[i] >= (lineCount - counter))
                    System.out.print("*  ");
                else
                    System.out.print("   ");
            System.out.println();
            counter++;
        }while(counter < lineCount);
        System.out.print("+");
        for(int i = 0; i <= lineCount; i++)
            System.out.print("---");
        System.out.println();
        System.out.print(' ');
        for(int i = 0; i < lineCount; i++)
            System.out.print("  "+(i+1));
        System.out.println();
    }

    public static void main(String[] args) {
        scanner = new Scanner(System.in);

        do {
            System.out.print("Numarul de coloane: ");

            while (!scanner.hasNextInt()) {
                System.out.print("Trebuie sa introduceti un numar" + "\nNumar coloane: ");
                scanner.next();
            }

            lineCount = scanner.nextInt();

            if(lineCount<=0)
                System.out.println("Numar intreg pozitiv diferit de 0");
        } while (lineCount <= 0);

        int[] coloane= new int[lineCount];

        for (int i = 0; i < lineCount; i++) {
            do {
                System.out.print("Valoarea " + (i+1) + " : ");

                while (!scanner.hasNextInt()) {
                    System.out.println("Trebuie sa introduceti un numar > 0" + "\nNumar: ");
                    scanner.next();
                }

                coloane[i]= scanner.nextInt();
            } while (coloane[i] <= 0);
        }
        scanner.close();
        printTable(lineCount, coloane);
    }
}