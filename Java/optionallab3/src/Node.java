import javafx.util.Pair;

import java.util.ArrayList;
import java.util.List;

abstract class Node {

    protected String name;
    protected List<Pair<Node,Integer> > adiacenta = new ArrayList<>();

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }




    @Override
    public String toString(){
        return name;
    }
}