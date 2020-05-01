package Store;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class ShopCart {
    private Map<Integer,Integer> productMap;
    private float pretTotal;
    private float pretFinal;

    public ShopCart() {
        pretFinal = 0;
        pretTotal = 0;
        productMap = new HashMap<Integer, Integer>();
    }

    public static float getDiscount(int count) {
        if(count<=5)
            return 1;
        if(count<=10)
            return 0.2f;
        return 0.6f;
    }

    public void addProduct(Products product , int amount ) {
        if( product != null ) {
            if (productMap.containsKey(product.getId())) {
                productMap.put(product.getId(), productMap.get(product.getId()) + amount);
            } else {
                productMap.put(product.getId(), amount);
            }
        }
    }

    public void calculatePrice() {
        Set<Integer> productsIds = productMap.keySet();
        pretFinal = pretTotal = 0;
        int currentIdCount;
        Products currentProduct;
        for( Integer i : productsIds ) {
            currentIdCount = productMap.get(i);
            currentProduct = Products.getProductById(i);
            pretTotal = pretTotal + currentProduct.getPrice() * currentIdCount;
            pretFinal = pretFinal + currentProduct.getPrice() * currentIdCount * getDiscount( currentIdCount );

            System.out.println(pretFinal);
            System.out.println(pretTotal);
        }
        System.out.println(pretFinal);
    }

    public boolean checkOut( Account userAccount ) {
        calculatePrice();
        System.out.println(pretFinal);
        if( userAccount.getBalance() < pretFinal )
            return false;
        userAccount.setBalance( userAccount.getBalance() - pretFinal );
        return true;
    }

    public float getPretTotal() {
        return pretTotal;
    }

    public float getPretFinal() {
        return pretFinal;
    }
}
