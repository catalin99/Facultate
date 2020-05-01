/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;
import java.time.LocalDate;

/**
 *
 * @author catal
 */
public class Application extends Project {
    Languages languages;
    String appName;
    String date;
    /**
    * Constructor
     * @param appname
     * @param localdata
    */
    public Application(String appname, LocalDate localdata, Languages lang) {
        this.languages = lang;
        this.appName=appname;
        this.date=localdata.toString();
    }

    public Languages getLanguages() {
        return languages;
    }

    public void setLanguages(Languages languages) {
        this.languages = languages;
    }

    @Override
    public String toString() {
        return "Application{" + "languages=" + languages + '}';
    }
}
