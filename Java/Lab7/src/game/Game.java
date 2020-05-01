package game;

import base.Board;
import base.Graph;
import game.Player;

import java.util.ArrayList;
import java.util.List;

public class Game {
    private Board board;
    private final ArrayList<Player> players = new ArrayList<>();

    public Game(Board board) {
        this.board = board;
    }

    public void addPlayer(Player player) {
        players.add(player);
        player.setGame(this);
        player.setGraph(new Graph(board.getNumberOfNodes()));
    }

    //Create getters and setters
    //Create the method that will start the game: start one thread for each player

    public Board getBoard() {
        return board;
    }

    public void setBoard(Board board) {
        this.board = board;
    }

    public ArrayList<Player> getPlayers() {
        return players;
    }

    public void start() {
        for (Player player : players) {
            new Thread(player).start();
        }
    }
}