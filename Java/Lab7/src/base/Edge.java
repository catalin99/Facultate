package base;

public class Edge {
    int source;
    int destination;

    public Edge(int source, int destination) {
        this.source = source;
        this.destination = destination;
    }

    @Override
    public String toString() {
        return "Edge{" + source + ", " + destination + '}';
    }
}
