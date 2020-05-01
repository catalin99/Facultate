package game;

import base.Board;
import base.Graph;

import java.util.Scanner;


public class Player implements Runnable {
    private String name;
    private Game game;
    private Graph graph;

    public static int THINKING_TIME = 500;

    public Player(String name) {
        this.name = name;
    }

    private boolean play() throws InterruptedException {
        while (game.getBoard().getComplete().getListOfEdges().size() > 0) {
            graph.addEdge(game.getBoard().extract());

            System.out.println(this.name);
            System.out.println(graph.getListOfEdges());

            Thread.sleep(THINKING_TIME);
        }
        return true;
    }

    @Override
    public void run() {
        try {
            play();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    public void setGame(Game game) {
        this.game = game;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Game getGame() {
        return game;
    }

    public Graph getGraph() {
        return graph;
    }

    public void setGraph(Graph graph) {
        this.graph = graph;
    }

    @Override
    public String toString() {
        return "Player{" +
                "name='" + name + '\'' +
                ", game=" + game +
                ", graph=" + graph +
                '}';
    }

// implement the run() method, that will repeatedly extract edges
    // implement the toString() method
}

