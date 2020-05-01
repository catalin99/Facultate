package Company;

import java.util.ArrayList;
import java.util.List;
import static java.util.Collections.*;

public class AssetManager extends Items {

    private List<Items> itemsList;

    AssetManager() {
        itemsList = new ArrayList<>();
    }

    public String getItemsList() {
        return toString();
    }

    public void add(Items ... obj) {
        for(Items x : obj)
            itemsList.add(x);
    }

    public List<String> getAssets() {
        List<String> temp = new ArrayList<>();
        for(Items x : itemsList) {

        }
        return temp;
    }

    public List<String> getItems() {
        List<String> temp = new ArrayList<>();
        for(Items x : itemsList)
            temp.add(x.getName());
        sort(temp);
        return temp;
    }

    @Override
    public String toString() {
        String s="";
        for(Items x : itemsList) {
            if (itemsList.indexOf(x) == (itemsList.size() - 1))
                s += x.getName() + ".";
            else
                s += x.getName() + ", ";
        }
        return s;
    }
}
