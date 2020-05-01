/***
 * @project lab3
 * @authors Mihai Burduhosu and Diana Orășanu on 04.03.2019
 */


import java.util.*;

public class TravelMap {

    private List< List<Node> > M;
    private List<Node> noduri;
    private List<Edge> edges;
    private List<Node> use;

    public TravelMap(){
        noduri = new ArrayList<>();
        edges = new ArrayList<>();
        M = new ArrayList<>();
        use = new ArrayList<>();
    }

    public void addNode(Node n){
        noduri.add(n);
    }

    public void addEdge(Node n1, Node n2, int cost, boolean bidir){
        Pair p1 = new Pair(n2, cost);
        Edge e1=new Edge(n1,n2,cost,bidir);
        edges.add(e1);
        //n1.adiacenta.add(p1);
    }

    public void addEdge(Node n1, Node n2, int cost){
//        boolean bidir = true;
        Pair p1 = new Pair(n2, cost);
        Pair p2 = new Pair(n1, cost);
        Edge e1=new Edge(n1,n2,cost,true);
        edges.add(e1);
        n1.adiacenta.add(p1);
        n2.adiacenta.add(p2);
    }

    public List<Node> getNodes(){
        noduri.sort(Comparator.comparing(Node::getName));
        return(noduri);
    }

    public int calcDistanta(Node n1, Node n2){
        use.clear();
        return distanta(n1, n2);
    }

    private int distanta(Node n1, Node n2){
        int minu = 99999999;
        Node nodi = n1;
        use.add(n1);

        if(n1 == n2){
            return 0;
        }
        for (int i = 0; i < n1.adiacenta.size(); i++) {
            if(n1.adiacenta.get(i).getValue() < minu && !use.contains(n1.adiacenta.get(i).getKey())){
                minu = n1.adiacenta.get(i).getValue();
                nodi = n1.adiacenta.get(i).getKey();
            }
        }
        return minu + distanta(nodi, n2);
    }

    @Override
    public String toString(){

        String myString = "";
        String arrow;
        for (int i = 0; i < edges.size(); i++) {
            if(edges.get(i).bidir){
                arrow = "\u21FF";
            }
            else
                arrow = "\u21FE";
            myString += edges.get(i).n1 + " "  + arrow + ' ' + edges.get(i).n2 + ' ' + edges.get(i).cost + "\n";
        }
        for (int i = 0; i < noduri.size(); i++) {
            System.out.println(noduri.get(i).getName()+ " " + noduri.get(i).adiacenta);
        }
        return myString;
    }



}
