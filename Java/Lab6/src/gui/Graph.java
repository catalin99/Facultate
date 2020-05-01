package gui;

import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;

public class Graph {
    private List<NodeDisplay> displayNodeList ;
    private List<EdgeDisplay> displayEdgeList ;
    private BufferedImage image;
    public Graph() {
        this.displayNodeList = new ArrayList<NodeDisplay>();
        this.displayEdgeList = new ArrayList<EdgeDisplay>();
        image=new BufferedImage(1366, 720, BufferedImage.TYPE_INT_ARGB);
    }

    public void addEdge(EdgeDisplay e)
    {
        displayEdgeList.add(e);
    }

    public void addNode(NodeDisplay n)
    {
        displayNodeList.add(n);
    }

    public void deleteEdge(EdgeDisplay e)
    {
        displayEdgeList.remove(e);
    }

    public void deleteNode(NodeDisplay n)
    {
        displayNodeList.remove(n);
    }

    public List<NodeDisplay> getDisplayNodeList() {
        return displayNodeList;
    }

    public List<EdgeDisplay> getDisplayEdgeList() {
        return displayEdgeList;
    }

    public BufferedImage getImage() {
        return image;
    }

    public void setImage(BufferedImage image) {
        this.image = image;
    }
}
