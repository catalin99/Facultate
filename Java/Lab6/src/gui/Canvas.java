package gui;

import javax.imageio.ImageIO;
import javax.swing.*;
//import java.awt.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.geom.Line2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.*;
import java.util.List;

import static java.lang.Thread.sleep;

public class Canvas extends JPanel {
    private final DrawingFrame frame;
    //Graphics graphics;
    Graph graph=new Graph();
    Graphics2D graphics = graph.getImage().createGraphics();
    int startX, startY;
    Point endPoint=null;
    Point startPoint=null;
//    Boolean move=false;


//    private List<DisplayNodesList> displayNodesList = new ArrayList<>();
//    private List<DisplayEdgesList> displayEdgesList= new ArrayList<>();
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
//        graphics=(Graphics2D) g;
//        String radiusStr=frame.getToolbar().getRadius();
//        int radius=Integer.parseInt(radiusStr);
//        drawNode(x, y, radius);
        frame.repaint();
        g.drawImage(graph.getImage(),0,0,null);
        if(startPoint!=null && endPoint!=null && frame.getToolbar().getForm()=="Edge" && frame.getControlPanel().getAction()=="Draw")
           drawEdge(startPoint.x,startPoint.y,endPoint.x,endPoint.y);
    }

    public Canvas(DrawingFrame frame) {
        super();
//        endPoint.x=0;
//        endPoint.y=0;
        this.frame=frame;
        init();
    }
    public void init()
    {
        this.setBackground(Color.white);
        graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON); //for "smooth" drawing
        this.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                //drawNode(e.getX(), e.getY());
                startX=e.getX();
                startY=e.getY();
                //repaint();
                String radiusStr=frame.getToolbar().getRadius();
                int radius=Integer.parseInt(radiusStr);
                if(frame.getToolbar().getForm()=="Node" && frame.getControlPanel().getAction()=="Draw")
                    drawNode(startX,startY,radius);
                else if(frame.getControlPanel().getAction()=="Erase")
                    delete(startX, startY);
            }
            public void mousePressed(MouseEvent e) {
                startPoint = e.getPoint();
            }

            public void mouseReleased(MouseEvent e) {
                startPoint = null;
            }
        });

        this.addMouseMotionListener(new MouseMotionAdapter() {

            public void mouseMoved(MouseEvent e) {
                endPoint = e.getPoint();
            }

            public void mouseDragged(MouseEvent e) {
                endPoint = e.getPoint();
//                repaint();
            }
        });
    }



    public void drawNode(int x, int y, int radius) {
        //Random rand = new Random();
        String colorStr=frame.getToolbar().getColor();
//        if(colorStr=="Blue")
        //graphics.setColor(new Color(rand.nextInt(0xFFFFFF))); //you may use a random color or the one specified in the toolbar
        graphics.setColor(transformColor(colorStr));
        graphics.fill(new NodeShape(x, y, radius));
        NodeDisplay d = new NodeDisplay(x,y,radius,transformColor(colorStr));
        graph.addNode(d);

    }

    public void drawEdge(int stX, int stY, int finX, int finY)
    {
        String colorStr1=frame.getToolbar().getColor();
        graphics.setColor(transformColor(colorStr1));
        graphics.setStroke(new BasicStroke(Integer.parseInt(frame.getToolbar().getRadius())));
        graphics.draw(new Line2D.Float(stX, stY, finX, finY));//Line(stX, stY, finX, finY);
        EdgeDisplay e = new EdgeDisplay(stX, stY, finX, finY,transformColor(colorStr1),Integer.parseInt(frame.getToolbar().getRadius()));
        graph.addEdge(e);
//        g.drawLine(stX, stY, finX, finY);
    }

    public Color transformColor(String color)
    {
        Map<String, Color> colorMap = new HashMap<>();
        colorMap.put("Blue",Color.blue);
        colorMap.put("Red",Color.red);
        colorMap.put("Green",Color.green);
        colorMap.put("Yellow",Color.yellow);
        colorMap.put("Black",Color.black);
        colorMap.put("Gray",Color.gray);
        colorMap.put("Cyan",Color.cyan);
        for(String it:colorMap.keySet())
        {
            if(it==color)
                return colorMap.get(it);
        }
        Random defaultColor=new Random();
        return new Color(defaultColor.nextInt(0xFFFFFF));

    }

    public void resetAll()
    {
        graph.setImage(new BufferedImage(1366, 720, BufferedImage.TYPE_INT_ARGB)) ;
        graphics = graph.getImage().createGraphics();
        new Canvas(frame);
    }

    public void loadDefault()
    {
        try {
            graph.setImage( ImageIO.read(new File("src/resources/canvas.png")));
        } catch (IOException e) {
            e.printStackTrace();
        }
        graphics = graph.getImage().createGraphics();
        new Canvas(frame);

    }

    private void delete(int x, int y)
    {
        deleteNode(x,y);
        deleteEdge(x,y);
        resetAll();
        redrawNodes();
        redrawEdges();
    }

    private void deleteNode(int x, int y){
        for(NodeDisplay n : graph.getDisplayNodeList())
        {
            int r=n.getRadius();
            int minX=n.getCoordX()-r;
            int maxX=n.getCoordX()+r;
            int minY=n.getCoordY()-r;
            int maxY=n.getCoordY()+r;

            if(x>=minX && x<=maxX && y>=minY && y<=maxY)
            {
                graph.deleteNode(n);
                break;
            }
        }
    }

    private void redrawNodes()
    {
        for(NodeDisplay n:graph.getDisplayNodeList())
        {
            drawNode(n.getCoordX(),n.getCoordY(),n.getRadius());
            try {
                sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    private void deleteEdge(int x, int y){

    }
    private void redrawEdges()
    {
        for(EdgeDisplay e:graph.getDisplayEdgeList())
        {
            drawEdge(e.getStartX(),e.getStartY(),e.getEndX(),e.getEndY());
        }
    }

    public Graph getGraph()
    {
        return this.graph;
    }
}
