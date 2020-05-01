package controller;

import entity.Catalog;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class ReportHTMLCommand implements Command {
    @Override
    public void execute(String[] input, Catalog catalog)  {
        String html="<html>\n"+"\t<body>\n";
        String temp=catalog.toString();

        String fin[]=temp.split("\n");
        for(int i=0; i<fin.length; i++)
        {
            html+="\t\t<p>\n";
            html+="\t\t\t";
            html+=fin[i];
            html+="\n\t\t</p>\n";
        }
        html+="\t</body>\n";
        html+="</html>\n";
        BufferedWriter writer = null;
        try {
            writer = new BufferedWriter(new FileWriter("src/resources/graph.html", false));
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            writer.write(html);
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        //System.out.println(html);
    }
}
