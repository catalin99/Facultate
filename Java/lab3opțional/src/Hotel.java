public class Hotel extends Node implements Classifiable{

    double rank;
    public Hotel(String s){
        this.name = s;
    }

    @Override
    public void setRank(double rank) {
        this.rank=rank;
    }

    @Override
    public double getRank() {
        return rank;
    }
}