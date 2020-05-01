package Company;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class RandomAlgorithm implements Algorithm {
    final int ITERATIONS = 10;

    @Override
    public List<Assets> solve( AssetManager manager , int maxValue ) {
        List<Assets> temp = manager.getAssets();
        List<Assets> temp2 = new ArrayList<Assets>();
        List<Assets> solution = new ArrayList<Assets>();
        boolean randomBool;
        float value , profit , solutionProfit = 0;
        Items aux;
        Random random = new Random();
//        System.out.println("Temp: " + temp);
        for( int it = 0 ; it < ITERATIONS ; ++it ) {
            temp2 = new ArrayList<Assets>();
            do {
                value = 0;
                profit = 0;
                temp2.clear();
                for( int i = 0 ; i < temp.size() ; ++i ) {
                    randomBool = random.nextBoolean();
                    if( randomBool == true ) {
                        temp2.add(temp.get(i));
                        aux = (Items)temp.get(i);
                        value += aux.getPrice();
                        profit += temp.get(i).computeProfit();
                    }
                }
//                System.out.println("Temp 2: " + temp2);
//                System.out.println("Value" + value);
                if( value <= maxValue )
                    break;
            }while(true);
            if( solutionProfit < profit ) {
                solutionProfit = profit;
                solution = temp2;
//                System.out.println("Solution: " + solution);
//                System.out.println("Profit: " + solutionProfit);
            }
        }
//        System.out.println("Solution: " + solution);
        return solution;
    }
}
