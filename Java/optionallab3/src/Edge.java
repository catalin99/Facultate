/***
 * @project lab3
 */

public class Edge {
    public Node n1;
    public Node n2;
    public int cost;
    public boolean bidir;
    public Edge(Node n1, Node n2, int cost, boolean bidir){
        this.bidir = bidir;
        this.cost = cost;
        this.n1 = n1;
        this.n2 = n2;
    }
}
