import java.time.Duration;
import java.time.LocalTime;

public interface Visitable {
    void setSchedule(LocalTime ... args);
    LocalTime[] getSchedule();


    static Duration getVisitingDuration(LocalTime open, LocalTime close){
        return Duration.between(open,close);
    }

    default void setHours(){
        setSchedule(LocalTime.of(9,30),LocalTime.of(22,0));
    }

}
