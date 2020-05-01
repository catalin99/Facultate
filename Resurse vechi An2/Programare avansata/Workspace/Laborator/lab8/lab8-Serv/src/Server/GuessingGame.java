package Server;

import java.util.Random;

public class GuessingGame {
    private String player;
    private int number;
    private int attempts;
    private int randomNumber;

    GuessingGame( String player , int number ) {
        this.player = player;
        this.number = number;
        attempts = 0;
        randomNumber = new Random().nextInt(number) + 1;
    }

    public String getPlayer() {
        return player;
    }

    public int getAttempts() {
        return attempts;
    }

    public int getNumber() {
        return number;
    }

    public int getRandomNumber() {
        return randomNumber;
    }

    String submit( int number ) {
        attempts++;
        if( number < this.randomNumber )
            return "Too small";
        else if ( number > this.randomNumber )
            return "Too big";
        else
            return "You got it!";
    }
}
