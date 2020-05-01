package gui;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.awt.event.ActionEvent;

public class ControlPanel extends JPanel {
    private final DrawingFrame frame;
    private JComboBox<String> action;

    public ControlPanel(DrawingFrame frame) {
        this.frame=frame;
        this.setLayout(new FlowLayout());

        this.setBorder(BorderFactory.createLineBorder(Color.blue));
        init();
    }
    public void init() {
        JButton loadButton = new JButton("Load");
        JButton saveButton = new JButton("Save");
        JButton resetButton = new JButton("Reset");
        String actionFields[]={"Draw", "Erase"};
        action=new JComboBox<>(actionFields);
        loadButton.addActionListener(this::loadFunction);
        saveButton.addActionListener(this::saveFunction);
        resetButton.addActionListener(this::resetFunction);
        this.add(action);
        this.add(loadButton);
        this.add(saveButton);
        this.add(resetButton);
    }

    private void saveFunction(ActionEvent e) {
        try {
            ImageIO.write(frame.getCanvas().getGraph().getImage(), "png", new File("src/resources/canvas.png"));
        } catch (IOException e1) {
            e1.printStackTrace();
        }

    }

    private void resetFunction(ActionEvent e)
    {
        frame.getCanvas().resetAll();
    }

    private void loadFunction(ActionEvent e)
    {
        frame.getCanvas().loadDefault();
    }
    public String getAction()
    {
        return action.getSelectedItem().toString();
    }
}
