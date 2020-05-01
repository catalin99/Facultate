package entity;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Serializable;
//import java.util.IllegalFormatException;

public class Graph implements Serializable {
    private String name;
    private String textGraph;
    private String imgGraph;

    public String citesteFisier ( String fis ) {
        FileReader f = null;
        String content="\0";
        try {
            System.out.println(" Deschidem fisierul " + fis);
            f = new FileReader(fis);
            int c;

            while ((c = f.read()) != -1)
                content+=(char) c;
        } catch (FileNotFoundException e) {
            System.err.println(" Fisierul nu a fost gasit ! ");
            System.err.println(" Exceptie : " + e.getMessage());
            System.exit(1);
        } catch (IOException e) {
            System.out.println(" Eroare la citirea din fisier ! ");
            e.printStackTrace();
        } finally {
            if (f != null) {
                System.out.println(" \nInchidem fisierul . ");
                try {
                    f.close();
                } catch (IOException e) {
                    System.err.println(" Fisierul nu poate fi inchis ! ");
                    e.printStackTrace();
                }
            }
            return content;
        }
    }
    public Graph(String name, String textGraph, String imgGraph) {
        this.name = name;
        if(!imgGraph.toString().endsWith(".pdf") && !imgGraph.toString().endsWith(".png"))
            throw new IllegalArgumentException("graph image should end with .pdf or .png");
        this.imgGraph = imgGraph;
        if(!textGraph.toString().endsWith(".tgf"))
            throw new IllegalArgumentException("graph tgf file end with .tgf");
        this.textGraph = textGraph;

    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getTextGraph() {
        return textGraph;
    }

    public void setTextGraph(String textGraph) {
        this.textGraph = textGraph;
    }

    public String getImgGraph() {
        return imgGraph;
    }

    public void setImgGraph(String imgGraph) {
        this.imgGraph = imgGraph;
    }

    @Override
    public String toString() {
        return  name + '\'' +
                "\n textGraph='\n" + citesteFisier(textGraph) + '\'' +
                "\n imgGraph='" + imgGraph + '\'';
    }
}
