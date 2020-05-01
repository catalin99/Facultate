public class Main {

    static int maxProfit(int[] prices) {
        int max=0, i;
        if(prices.length == 0)
            return 0;
        int min = prices[0];
        for(i = 1;i < prices.length; i++) {
            if(prices[i-1] < min)
                min = prices[i-1];
            if(max < prices[i]-min)
                max = prices[i] - min;
        }
        return max;
    }

    public static void main(String[] args) {
        int[] stiva = {2,7,17,1,8,3,20,5,100,0};
        System.out.println(maxProfit(stiva));
    }
}
