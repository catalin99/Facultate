package Company;

public class Building extends Items implements Assets {

    private int area;

    Building(String name, int area, int price) throws NameException {
        setName(name);
        setPrice(price);
        this.area = area;
    }

    @Override
    public int computeProfit() { return area/getPrice();
    }

    public int getArea() {
        return area;
    }
}
