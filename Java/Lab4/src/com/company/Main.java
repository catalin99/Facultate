package com.company;
import java . io .*;
import java.util.Scanner;

public class Main {


    public static void main(String[] args){
//        citesteFisier("src/k3.tgf");
        Catalog catalog = new Catalog("graphs");
        catalog.add (new Graph("K3", "src/k3.tgf", "src/Untitled.png"));
        catalog.add (new Graph("Petersen", "src/petersen.tgf", "src/petersen.png"));
        catalog.list();
//        catalog.open("K3");
//        catalog.open("Petersen");
//        CatalogIO catalogIO=null;
//        catalog.save("src/catalog.dat");
        catalog.load("src/catalog.dat");
        Scanner scanner = new Scanner(System.in);
//        String command ="\0";
        String command = scanner.next();
//        System.out.println(command);
//        String temp=new String(command);
        String words[]=command.split(",");
        switch (words[0]){
            case "add":
            {
                Command exec=new AddCommand();
                exec.execute(words, catalog);
                break;
            }
            case "list":
            {
                Command exec=new ListCommand();
                exec.execute(words, catalog);
                break;
            }
            case "save":
            {
                Command exec=new SaveCommand();
                exec.execute(words, catalog);
                break;
            }
            case "load":
            {
                Command exec=new LoadCommand();
                exec.execute(words, catalog);
                break;
            }
            case "open":
            {
                Command exec=new OpenCommand();
                exec.execute(words, catalog);
                break;
            }
            case "report":
            {
                Command exec=new ReportHTMLCommand();
                exec.execute(words, catalog);
                break;
            }
            default:
                throw new IllegalArgumentException("Comandă greșită");
        }
//        System.out.println("test");
    }
}
