package gui;

import javax.swing.*;
import java.awt.*;

public class DrawingFrame extends JFrame {
    private Toolbar toolbar;
    private Canvas canvas;
    private ControlPanel controlPanel;

    public DrawingFrame() {
        super("Graph drawing manager");
        toolbar=new Toolbar(this);
        canvas =new Canvas(this);
        controlPanel=new ControlPanel(this);
        init();
    }

    private void init(){
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setSize(600, 600);
        this.add(toolbar, BorderLayout.NORTH);
        this.add(canvas,BorderLayout.CENTER);
        this.add(controlPanel, BorderLayout.SOUTH);
//        this.pack();
        this.setVisible(true);
    }

    public Toolbar getToolbar()
    {
        return toolbar;
    }
    public Canvas getCanvas() { return canvas; }
    public ControlPanel getControlPanel() { return controlPanel; }
}
