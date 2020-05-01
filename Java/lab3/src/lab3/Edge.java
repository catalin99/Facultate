package lab3;


public class Edge {

    private Node startNode;
    private Node destinationNode;
    private int cost;
    private boolean isBidirectional = false;

    public Node getStartNode() {
        return startNode;
    }

    public Node getDestinationNode() {
        return destinationNode;
    }

    public int getCost() {
        return cost;
    }

    public boolean isBidirectional() {
        return isBidirectional;
    }

    public void setStartNode(Node startNode) {
        this.startNode = startNode;
    }

    public void setDestinationNode(Node destinationNode) {
        this.destinationNode = destinationNode;
    }

    public void setCost(int cost) {
        this.cost = cost;
    }

    public void setBidirectional(boolean bidirectional) {
        isBidirectional = bidirectional;
    }
}
