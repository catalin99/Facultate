public class Restaurant extends Node implements Payable {

    double fee;

    public Restaurant(String s){
        this.name = s;
    }

    @Override
    public void setFee(double fee) {
        this.fee=fee;
    }

    @Override
    public double getFee() {
        return fee;
    }
}
