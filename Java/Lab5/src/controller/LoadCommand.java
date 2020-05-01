package controller;

import entity.Catalog;

public class LoadCommand implements Command {
    @Override
    public void execute(String input[], Catalog catalog) {
//        String words[]=input.split(" ");
        catalog.load(input[1]);
    }
}
