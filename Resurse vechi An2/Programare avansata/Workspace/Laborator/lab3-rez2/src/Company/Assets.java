package Company;

public interface Assets {
    float computeProfit();
    default float riskFactor() {
        return 0;
    }
}
