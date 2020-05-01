package entity;

import java.io.*;
import java.util.List;

public class CatalogIO {
    public static List<Graph> load(String path, List<Graph> graphList){
        try {
            FileInputStream fileInputStream=new FileInputStream(path);
            ObjectInputStream objectInputStream=new ObjectInputStream(fileInputStream);
            graphList= (List<Graph>) objectInputStream.readObject();
            System.out.println("All the data loaded from: "+path);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        return graphList;
    }

    public static void save(String path, List<Graph> graphList){
        try {
            FileOutputStream fileOutputStream=new FileOutputStream(path);
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
            objectOutputStream.writeObject(graphList);
            objectOutputStream.close();
            fileOutputStream.close();
            System.out.println("All the data saved in: "+path);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
