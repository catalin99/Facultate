package WordGame;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        Game game = new Game();
        game.setBag(new Bag());
        game.setBoard(new Board());
        try {
            game.setDictionary(new Dictionary());
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        game.addPlayer(new Player("Player 1"));
        game.addPlayer(new Player("Player 2"));
        game.addPlayer(new Player("Player 3"));
        game.start();
    }
}
