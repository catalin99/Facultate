package Company;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class AssetManager extends Items {

    private List<Items> itemsList;
    AssetManager() {
        itemsList = new ArrayList<>();
    }

    public String getItemsList() {
        return toString();
    }

    public void add(Items ... obj) {
        for(Items x : obj) {
            itemsList.add(x);
        }
    }

    public List<Assets> getAssets() {
        List<Assets> temp = new ArrayList<Assets>();
        for( Items x : itemsList ) {
            if( x instanceof Assets ) {
                temp.add((Assets)x);
            }
        }
        // lamba
        temp.sort((o1, o2) -> (int)(o1.computeProfit() - o2.computeProfit()));
        return temp;
    }

    public List<Items> getItems() {
        itemsList.sort(new Comparator<Items>() {
            @Override
            public int compare(Items o1, Items o2) {
                return (o1.getName().compareTo(o2.getName()));
            }
        });
        return itemsList;
    }

    @Override
    public String toString() {
        String s="";
        for(Items x : itemsList) {
            if (itemsList.indexOf(x) == (itemsList.size() - 1)) {
                s += x.getName() + ".";
            }
            else {
                s += x.getName() + ", ";
            }
        }
        return s;
    }

    public Portofolio createPortofolio( Algorithm alg , int maxValue ) {
        return new Portofolio( alg.solve( this , maxValue ) );
    }
}