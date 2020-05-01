package base;

import base.Edge;

import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;

public class Graph {
    private LinkedList<Edge> edges;
    private int numberOfNodes;

    public Graph(int numberOfNodes) {
        edges = new LinkedList<Edge>();
        this.numberOfNodes = numberOfNodes;
    }

    public void addEdge(Edge edge) {
            edges.add(edge);
    }

    public void removeEdge(Edge edge) {
        edges.remove(edge);
    }

    public void show() {
        for (Edge edge : edges) {
            System.out.println(edge);
        }
    }

    public Edge pollFirst() {
        return edges.pollFirst();
    }

    public LinkedList<Edge> getListOfEdges() {
        return edges;
    }

    public void shuffleEdges(){
        Collections.shuffle(edges);
    }

    public void setListOfEdges(LinkedList<Edge> listOfEdges) {
        this.edges = listOfEdges;
    }

    public int getNumberOfNodes() {
        return numberOfNodes;
    }

    public void setNumberOfNodes(int numberOfNodes) {
        this.numberOfNodes = numberOfNodes;
    }

    @Override
    public String toString() {
        return "Graph{" + "\n" + "Number of vertices: " + numberOfNodes + "\n" + "Edges: " + edges + "}";
    }
}
