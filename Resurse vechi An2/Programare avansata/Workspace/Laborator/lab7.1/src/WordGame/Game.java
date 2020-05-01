package WordGame;

import java.util.ArrayList;
import java.util.List;

public class Game {
    private Bag bag;
    private Board board;
    private Dictionary dictionary;
    private final List<Player> players = new ArrayList<>();
    public void addPlayer(Player player) {
        players.add(player);
        player.setGame(this);
    }

    public Bag getBag() {
        return bag;
    }

    public void setBag(Bag bag) {
        this.bag = bag;
    }

    public Board getBoard() {
        return board;
    }

    public void setBoard(Board board) {
        this.board = board;
    }

    public Dictionary getDictionary() {
        return dictionary;
    }

    public void setDictionary(Dictionary dictionary) {
        this.dictionary = dictionary;
    }

    public List<Player> getPlayers() {
        return players;
    }

    public void start() {
        for( Player p : players ) {
            new Thread(p).start();
        }
    }
    //Create getters and setters
    //Create the method that will start the game: start one thread for each player
}
