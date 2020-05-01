package gui.doc.manager;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.awt.Desktop;

public abstract class Document implements Serializable {
    String title;
    String path;
    int year;
    List<String> authors;

    public Document(String title , String path , int year , String ... authors) throws YearException, FileNotFoundException {
        if( year > Calendar.getInstance().get(Calendar.YEAR))
            throw new YearException("We are not there yet!\n");
        if( !new File(path).exists())
            throw new FileNotFoundException("Calea " + path + " este invalida");
        this.title = title;
        this.path = path;
        this.year = year;
        this.authors = new ArrayList<String>();
        for( String a : authors ) {
            this.authors.add(a);
        }
    }

    public class YearException extends Exception {
        public YearException( String s) {
            super(s);
        }
    }

    public void open() throws IOException {
        Desktop.getDesktop().open(new File(path));
    }

}