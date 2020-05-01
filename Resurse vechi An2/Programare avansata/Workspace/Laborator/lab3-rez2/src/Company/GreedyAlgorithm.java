package Company;

import java.util.ArrayList;
import java.util.List;

public class GreedyAlgorithm implements Algorithm {
    @Override
    public List<Assets> solve( AssetManager manager , int maxValue ) {
        List<Assets> temp = manager.getAssets();
        List<Assets> solution = new ArrayList<Assets>();
        Items aux;
        for( int i = temp.size() - 1 ; i >= 0 && maxValue > 0 ; --i ){
            aux = (Items)temp.get(i);
            if( maxValue >= aux.getPrice()) {
                solution.add((Assets)aux);
                maxValue -= aux.getPrice();
            }
        }
        return solution;
    }
}
