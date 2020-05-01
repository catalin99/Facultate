package WordGame;

import java.util.List;

public class Player implements Runnable {
    private String name;
    private Game game;

    Player(String name) {
        this.name = name;
    }

    private boolean createSubmitWord() throws InterruptedException {
        List extracted = game.getBag().extractLetters(1);
        if (extracted.isEmpty()) {
            return false;
        }
        StringBuilder word = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            word.append(extracted.get(0));
        }
//       if( !game.getDictionary().getWords().contains(word.toString()) )
//         return false;
        game.getBoard().addWord(this, word.toString());
        Thread.sleep(300);
        return true;
    }

    public String getName() {
        return name;
    }

    public void setName( String name ) {
        this.name = name;
    }

    public Game getGame() {
        return game;
    }

    public void setGame( Game game ) {
        this.game = game;
    }

    @Override
    public String toString() {
        return name;
    }

    @Override
    public void run() {
        while (true) {
            try {
                if (!createSubmitWord()) {
                    break;
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    //implement the run() method, that will repeatedly create and submit words
    //implement the toString() method
}
