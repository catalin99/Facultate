package Company;

import java.util.ArrayList;
import java.util.List;

public abstract class Items {
    private static List<String> namesList;
    private String name;
    private int price;

    static {
        namesList = new ArrayList<>();
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) throws NameException {
        if(!namesList.isEmpty() && namesList.contains(name))
            throw new NameException("Numele deja exista!");
        else {
            this.name = name;
            namesList.add(name);
        }
    }

    public List<String> getnamesList() {
        return namesList;
    }

    public void setnamesList(List<String> namesList) {
        this.namesList = namesList;
    }

}
