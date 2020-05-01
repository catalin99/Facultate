package lab3;


//import Node;
//import Classifiable;
//import Payable;

public class Hotel extends Node implements Classifiable {

    private int classification;

    public Hotel(String name, int classification) {
        this.name = name;
        this.classification = classification;
    }

    @Override
    public int getClassification() {
        return classification;
    }
}
