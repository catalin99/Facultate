package lab3;



//import Node;
//import Classifiable;
//import Payable;

public class Restaurant extends Node implements Classifiable {

    private int classification;

    public Restaurant(String name, int classification) {
        this.name = name;
        this.classification = classification;
    }

    @Override
    public int getClassification() {
        return classification;
    }
}