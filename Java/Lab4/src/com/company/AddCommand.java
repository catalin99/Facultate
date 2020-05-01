package com.company;

public class AddCommand implements Command{
    @Override
    public void execute(String input[], Catalog catalog) {
//        String words[]=input.split(" ");
        catalog.add(new Graph(input[1], input[2], input[3]));
    }
}
