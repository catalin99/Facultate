package controller;

import entity.Catalog;

public interface Command {
    public void execute(String input[], Catalog catalog);

}
