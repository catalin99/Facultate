package lab3;



//import Node;
//import Payable;
//import Visitable;

public class Museum extends Node implements Visitable, Payable {

    private String openingHour;
    private String closingHour;
    private double entryFee;

    public Museum(String name, String openingHour, String closingHour, double entryFee) {
        this.name = name;
        this.openingHour = openingHour;
        this.closingHour = closingHour;
        this.entryFee = entryFee;
    }

    @Override
    public double getEntryFee() {
        return entryFee;
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
