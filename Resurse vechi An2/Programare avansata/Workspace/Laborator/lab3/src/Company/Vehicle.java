package Company;

public class Vehicle extends Items implements Assets {

    private int performance;

    Vehicle(String name, int performance, int price) throws NameException {
        setName(name);
        setPrice(price);
        this.performance=performance;
    }

    @Override
    public int computeProfit() {
        return performance/getPrice();
    }

    public int getPerformance() {
        return  performance;
    }
}
