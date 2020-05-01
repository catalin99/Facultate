package Company;

import java.util.ArrayList;
import java.util.List;

public class Portofolio {
    private List<Assets> bestAssets;

    Portofolio( List<Assets> bestAssets ) {
        this.bestAssets = bestAssets;
    }

    public List<Assets> getBestAssets() {
        return bestAssets;
    }

    public void setBestAssets( List<Assets> bestAssets ) {
        this.bestAssets = bestAssets;
    }

    @Override
    public String toString() {
        return bestAssets.toString();
    }
}
