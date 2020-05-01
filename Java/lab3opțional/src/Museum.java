import java.time.LocalTime;

public class Museum  extends Node implements Visitable, Payable{
    LocalTime[] schedule = new LocalTime[2];
    double fee;

    public Museum(String s){
        this.name = s;
        setHours();
    }
    @Override
    public void setSchedule(LocalTime ... args) {
        schedule[0]=args[0];
        schedule[1]=args[1];

    }
    @Override
    public LocalTime[] getSchedule() {
        return schedule;
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
