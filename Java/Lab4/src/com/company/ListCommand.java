package com.company;

public class ListCommand implements Command {
    @Override
    public void execute(String input[], Catalog catalog) {
        catalog.list();
    }
}
