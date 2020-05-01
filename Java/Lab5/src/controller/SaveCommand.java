package controller;

import entity.Catalog;

public class SaveCommand implements Command {
    @Override
    public void execute(String input[], Catalog catalog) {
//        String words[]=input.split(" ");
        catalog.save(input[1]);
    }
}
