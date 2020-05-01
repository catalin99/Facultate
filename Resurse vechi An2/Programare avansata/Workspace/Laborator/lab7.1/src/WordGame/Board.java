package WordGame;

import java.util.ArrayList;
import java.util.List;

public class Board {
    private final List<String> wordList;

    Board() {
        wordList = new ArrayList<>();
    }

    synchronized final void addWord ( Player p , String word ) throws NullPointerException {
        if ( word == null ) {
            throw new NullPointerException("Please enter a word!");
        }
        if( p == null ) {
            throw new NullPointerException("An existing player must introduce a word!");
        }
        wordList.add(word);
        System.out.println("Player " + p.getName() + " submitted the word " + word );
    }
}
