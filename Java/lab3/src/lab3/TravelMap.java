package lab3;


/*
import Edge;
import Node;*/

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class TravelMap {

    private List<Node> nodes = new ArrayList<Node>();
    private List<Edge> edges = new ArrayList<Edge>();

    public void addNode(Node node)
    {
        nodes.add(node);
    }

  

    public void addEdge(Node startNode, Node destinationNode, int cost)
    {
        Edge edge = new Edge();
        edge.setStartNode(startNode);
        edge.setDestinationNode(destinationNode);
        edge.setCost(cost);
        edge.setBidirectional(true);
        edges.add(edge);
    }

    public void addEdge(Node startNode, Node destinationNode, int cost, boolean isOneWay)
    {
        Edge edge = new Edge();
        edge.setStartNode(startNode);
        edge.setDestinationNode(destinationNode);
        edge.setCost(cost);
        edges.add(edge);
    }

    public List<Node> getNodes(){
        return nodes.stream().sorted((s1, s2) -> s1.getName().compareTo(s2.getName())).collect(Collectors.toList());
    }
}
