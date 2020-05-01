/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3;


public class lab3 {

    public static void main(String[] args) {
        TravelMap map = new TravelMap();

        Hotel h1 = new Hotel("Transilvania",1);

        Museum m1 = new Museum("Taranului Roman","8:00 AM","19:00 PM",3.5);
        Museum m2 = new Museum("History","8:00 AM","19:00 PM",5);

        Restaurant r1 = new Restaurant("Doppo Poco",5);

        Church c1 = new Church("Sf Nicolae BT","6:00 AM","21:00 PM");
        Church c2 = new Church("Sf Nicolae BC","6:00 AM","21:00 PM");

        map.addNode(h1);
        map.addNode(m1);
        map.addNode(m2);
        map.addNode(r1);
        map.addNode(c1);
        map.addNode(c2);

        map.addEdge(h1, c1, 15);
        map.addEdge(h1,m2,10);
        map.addEdge(m2,m1,1,false);
        map.addEdge(m2,c1,1);
        map.addEdge(c1,c2,1);
        map.addEdge(c2,c2,1);
        map.addEdge(c2,r1,10);

        System.out.println("The map is: \n" + map.getNodes());
    }
}

