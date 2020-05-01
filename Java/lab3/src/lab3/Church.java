package lab3;



//import Node;
//import Classifiable;
//import Visitable;

public class Church extends Node implements Visitable {

    private String openingHour;
    private String closingHour;

    public Church(String name, String openingHour, String closingHour) {
        this.name = name;
        this.openingHour = openingHour;
        this.closingHour = closingHour;
    }

    @Override
    public String getOpeningHour() {
        return openingHour;
    }

    @Override
    public String getClosingHour() {
        return closingHour;
    }
}
