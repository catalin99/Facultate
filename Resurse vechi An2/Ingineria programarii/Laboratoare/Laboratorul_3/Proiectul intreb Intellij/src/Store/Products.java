package Store;

import java.util.ArrayList;
import java.util.List;

public class Products {
    static List<Products> productsList;
    private int id;
    private int price;
    private String name;
    private String description;

    static {
        productsList = new ArrayList<Products>();
    }

    Products() {
        id = 0;
        price = 0;
        name = "No Name";
        description = "No Description";
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public static void addNewProduct(String name, int price) throws ExceptionProducts{
        Products produsNou = new Products();
        produsNou.setName(name);
        produsNou.setPrice(price);
        for( Products produs : productsList ) {
            if( produs.equals(produsNou))
                throw new ExceptionProducts("Produsul deja exista!");
        }
        if( productsList.isEmpty()) {
            produsNou.setId(1);
        }
        else {
            produsNou.setId(productsList.get(productsList.size() - 1).id + 1);
        }
        productsList.add( produsNou );
    }

    public static Products getProductById( int id ) {
        for( Products produs : productsList ) {
            if( id == produs.getId() )
                return produs;
        }
        return null;
    }

    @Override
    public int hashCode() {
        int hash=1;
        hash = hash * 17 + name.hashCode();
        hash = hash * 31 + description.hashCode();
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if( obj == null )
            return false;
        if( !( obj instanceof Products))
            return false;
        Products temp = (Products)obj;
        if( this.hashCode() != temp.hashCode() )
            return false;
        return true;
    }

public static class ExceptionProducts extends Exception {
    public ExceptionProducts(String s) {
        super(s);
    }
}
}
