
import java.util.ArrayList;
import java.util.List;

abstract class Node {

    public String name;
    public List<Pair> adiacenta = new ArrayList<>();

    public void setName(String Name) {
        this.name = Name;
    }

    public String getName() {
        return name;
    }




    @Override
    public String toString(){
        return name;
    }
}
