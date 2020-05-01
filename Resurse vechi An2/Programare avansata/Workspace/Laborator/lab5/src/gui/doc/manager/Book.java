package gui.doc.manager;

import java.io.FileNotFoundException;

public class Book extends Document{
    public Book(String title , String path , int year , String ... authors ) throws YearException, FileNotFoundException {
        super(title,path,year,authors);
    }
}
