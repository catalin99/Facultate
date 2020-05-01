package WordGame;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Dictionary {
    private List<String> words;

    Dictionary() throws FileNotFoundException {
        words = new ArrayList<String>();
        Scanner reader = new Scanner(new FileReader("resurse/dictionar.txt"));
        String word;
        while( reader.hasNext()) {
            word = reader.next();
            words.add(word);
        }
    }

    void printWords() {
        for( String x : words ) {
            System.out.println(x);
        }
    }

    List<String> getWords() {
        return words;
    }
}
