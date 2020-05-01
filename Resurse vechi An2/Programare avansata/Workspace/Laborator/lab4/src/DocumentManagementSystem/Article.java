package DocumentManagementSystem;

import java.io.FileNotFoundException;

public class Article extends Document{
    public Article(String title , String path , int year , String ... authors ) throws YearException, FileNotFoundException {
        super(title,path,year,authors);
    }
}
