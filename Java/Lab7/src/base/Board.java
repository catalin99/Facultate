package base;

import base.Edge;
import base.Graph;

public class Board {
    private final Graph complete;
    private int numberOfNodes;

    public Board(int numberOfNodes) {
        this.numberOfNodes = numberOfNodes;
        // create the complete graph
        // shuffle its edges
        complete = new Graph(numberOfNodes);

        for (int i = 0; i < numberOfNodes; i++) {
            for (int j = 0; j < numberOfNodes; j++) {
                if (i != j)
                    complete.addEdge(new Edge(i, j));
            }
        }

        complete.shuffleEdges();
    }

    public void show() {
        complete.show();
    }

    public synchronized Edge extract() {
        // replace the dots so that the board is thread-safe
        Edge edge = complete.pollFirst();
        return edge;
    }

/*
    public boolean isEmpty() {

    }
*/


    public Graph getComplete() {
        return complete;
    }

    public int getNumberOfNodes() {
        return numberOfNodes;
    }

    public void setNumberOfNodes(int numberOfNodes) {
        this.numberOfNodes = numberOfNodes;
    }
}