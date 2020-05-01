package gui;

import controller.Command;
import controller.LoadCommand;
import controller.OpenCommand;
import controller.SaveCommand;
import entity.Catalog;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class ControlPanel extends JPanel {
    private Catalog catalog;
    public ControlPanel(Catalog frame) {
        init(frame);
    }
    private void init(Catalog frame) {
        this.catalog=frame;
        this.setLayout(new FlowLayout());

        this.setBorder(BorderFactory.createLineBorder(Color.blue));

        JButton loadBtn = new JButton("Load");
        JButton saveBtn = new JButton("Save");
        loadBtn.addActionListener(this:: loadFunct);
        saveBtn.addActionListener(this::saveFunct);
        this.add(loadBtn);
        this.add(saveBtn);


    }
    private void loadFunct(ActionEvent e)
    {
        Command exec=new LoadCommand();
        String load[]={"load", "src/resources/catalog.dat"};
        exec.execute(load, catalog);
    }

    private void saveFunct(ActionEvent e)
    {
        Command exec=new SaveCommand();
        String save[]={"save", "src/resources/catalog.dat"};
        exec.execute(save, catalog);
    }
}
