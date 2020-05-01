import java.time.LocalTime;

public class Church extends Node implements Visitable {
    LocalTime [] schedule;

    public Church(String s){
        this.name = s;
        setHours();
    }
    @Override
    public void setSchedule(LocalTime... args) {
        this.schedule=new LocalTime[2];
        schedule[0]=args[0];
        schedule[1]=args[1];
    }
    @Override
    public LocalTime[] getSchedule(){
        return schedule;
    }
}
