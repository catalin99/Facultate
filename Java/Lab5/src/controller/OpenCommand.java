package controller;

import entity.Catalog;

public class OpenCommand implements Command {
    @Override
    public void execute(String input[], Catalog catalog) {
//        System.out.println(input);
//        String words[]=input.split("-");
//        System.out.println(input[1]);
        catalog.open(input[1]);
    }
}
