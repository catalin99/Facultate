package entity;


import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Catalog implements Serializable {
    List<Graph> G=new ArrayList<>() ;
    String catalogPath;

    public Catalog(String catalogName) {
        this.catalogPath = catalogName;
    }

    public void add(Graph g)
    {
        G.add(g);
    }

    @Override
    public String toString() {
        return "Catalog path " + catalogPath + " {\n" +
                "G= " + G +
                 "\n}";
    }

    public List<Graph> getG() {
        return G;
    }

    public void list()
    {
        System.out.println(toString());
    }

    public void open(String fileToOpen)
    {
        //File file=new File("src/Untitled.png");
        File file=new File(fileToOpen);
        for(int i=0; i<G.size(); i++)
        {
            if(G.get(i).getName()==fileToOpen)
            {
                file=new File(G.get(i).getImgGraph());
                break;
            }
        }
//        File file=new File(fileToOpen);
        Desktop desktop=Desktop.getDesktop();
        try {
            desktop.open(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void save (String path) {
        CatalogIO.save(path, G);
    }
    public void load (String path){
        CatalogIO.load(path, G);
    }
}
