package gui.doc.manager;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Catalog implements Serializable {
    private List<Document> entries;

    public Catalog() {
        entries = new ArrayList<Document>();
    }

    public void add( Document doc) {
        entries.add(doc);
    }

    public void list() {
        int index = 0;
        for( Document doc : entries ) {
//            System.out.println(index);
//            index++;
//            if (doc instanceof Book) {
//                System.out.println("Cartea: \n");
//            } else {
//                System.out.println("Articolul: \n");
//            }
            System.out.println(doc.title + ", " + doc.year + " [ " + doc.path + " ] ");
//            System.out.println("Titlu: " + doc.title + "\n");
//            System.out.println("Calea: " + doc.path + "\n");
//            System.out.println("Anul: " + doc.year + "\n");
//            System.out.println("Autorii: " + doc.authors + "\n\n");
        }
    }

    public void open( int index ) throws IOException,ArrayIndexOutOfBoundsException {
        entries.get(index).open();
    }

    public void save(String path) throws FileNotFoundException , IOException {
        if( !new File(path).exists())
            throw new FileNotFoundException( "Cale invalida: " + path + " !");
        FileOutputStream fos = new FileOutputStream(path);
        ObjectOutputStream out = new ObjectOutputStream(fos);
        out.writeObject( this );
        out.flush();
        fos.close();
    }

    public void load( String path ) throws IOException {
        if( !new File(path).exists() )
            throw new FileNotFoundException("Cale invalida: " + path + " !");
        FileInputStream fis = new FileInputStream(path);
        ObjectInputStream in = new ObjectInputStream(fis);
        try {
            this.entries = ((Catalog)in.readObject()).entries;
        }catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}

