import java.time.Duration;
import java.time.LocalTime;

/***
 * @project lab3
 */

public class Main {

    public static void main(String[] args) {
        Hotel v1 = new Hotel("California");
        Museum v2 = new Museum("Oului");
        Church v3 = new Church("Sf Nectarie");
        Restaurant v4 = new Restaurant("Chinezesc");
        Museum v5 = new Museum("Țăranului Român");
        Church v6 = new Church("National Cathedral");
        Museum v7 = new Museum("Natural");


        v1.setRank(2.3);
        v2.setSchedule(LocalTime.of(10,0),LocalTime.of(22,0));
        v3.setSchedule(LocalTime.of(10,0),LocalTime.of(20,0));
        v4.setFee(230);
        v5.setSchedule(LocalTime.of(11,7),LocalTime.of(20,0));
        v6.setSchedule(LocalTime.of(7,0),LocalTime.of(21,0));
//
//        System.out.println(v1.getName()+ " " + v1.getRank());
//        System.out.println(v2.getName()+ " " + v2.getSchedule()[0] + " " + v2.getSchedule()[1]);
//        System.out.println(v3.getName()+ " " + v3.getSchedule()[0] + " " + v3.getSchedule()[1]);
//        System.out.println(v4.getName()+ " " + v4.getFee());
        System.out.println(v7.getSchedule()[0] + " " + v7.getSchedule()[1]);

        TravelMap map = new TravelMap();

        map.addNode(v1);
        map.addNode(v2);
        map.addNode(v3);
        map.addNode(v4);
        map.addNode(v5);
        map.addNode(v6);

        map.addEdge(v1, v2, 15); //two way street by default
        map.addEdge(v3, v2, 1, false); //one-way street
        map.addEdge(v1, v3, 10);
        map.addEdge(v3, v4, 2);
        map.addEdge(v5, v6, 1);
        map.addEdge(v5, v4, 1);
        map.addEdge(v2, v6, 10);



        System.out.println("The map is: \n" + map.getNodes());
        System.out.println(map);
        System.out.println(map.calcDistanta(v3,v4));
        System.out.println(map.calcDistanta(v4,v5));

        //System.out.println(Visitable.getVistingDuration());
        //2
        map.getNodes().stream().filter(node -> (node instanceof Visitable) && !(node instanceof Payable)).
                forEach(y->System.out.println(y));

        //3
        double result2 = map.getNodes().stream().filter(node -> node instanceof Payable).
                        mapToDouble(node -> ((Payable) node).getFee()).average().getAsDouble();
        System.out.println(result2);
        Duration tmp = Visitable.getVisitingDuration(v5.getSchedule()[0], v5.getSchedule()[1]);
        System.out.println(tmp.toString());
    }
}
