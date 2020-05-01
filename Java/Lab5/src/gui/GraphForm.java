package gui;

import controller.Command;
import controller.OpenCommand;
import controller.ReportHTMLCommand;
import entity.Catalog;
import entity.Graph;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

public class GraphForm extends JPanel {
    private final CatalogFrame frame;

    private JPanel textBoxesPanel;
    private JPanel characteristicsPanel;
    private JPanel controlPanel;

    private JComboBox<String> graphTypeList;
    private JSpinner verticesField;
    private JSpinner edgesField;

    private TextField nameField;
    private TextField defPathField;
    private TextField imgPathField;


    GraphForm(CatalogFrame frame){
        this.frame = frame;

        textBoxesPanel = new JPanel();
        characteristicsPanel = new JPanel();
        controlPanel = new JPanel();

        init();
    }

    private void init() {
        this.setLayout(new GridLayout(3,1));
        textBoxesPanel.setLayout(new GridLayout(6,1));
        characteristicsPanel.setLayout(new FlowLayout());
        controlPanel.setLayout(new FlowLayout());

        // textBoxesPanel
        JLabel nameLabel = new JLabel("Name of the graph");
        JLabel defPathLabel = new JLabel("Path of the definition file");
        JLabel imgPathLabel = new JLabel("Path of the image file");

        nameField = new TextField("K3");
        defPathField = new TextField("src/resources/k3.tgf");
        imgPathField = new TextField("src/resources/Untitled.png");

        textBoxesPanel.add(nameLabel);
        textBoxesPanel.add(nameField);
        textBoxesPanel.add(defPathLabel);
        textBoxesPanel.add(defPathField);
        textBoxesPanel.add(imgPathLabel);
        textBoxesPanel.add(imgPathField);
        // characteristicsPanel
        JLabel graphLabel = new JLabel("Graph type");
        JLabel verticesNrLabel = new JLabel("Number of vertices");
        JLabel edgesNrLabel = new JLabel("Number of edges");
        String[] graphTypes = {"simple","directed"};
        graphTypeList = new JComboBox<>(graphTypes);
        verticesField  = new JSpinner(new SpinnerNumberModel());
        edgesField = new JSpinner(new SpinnerNumberModel());

        characteristicsPanel.add(graphLabel);
        characteristicsPanel.add(graphTypeList);
        characteristicsPanel.add(verticesNrLabel);
        characteristicsPanel.add(verticesField);
        characteristicsPanel.add(edgesNrLabel);
        characteristicsPanel.add(edgesField);
        // controlPanel
        JButton addButton = new JButton("Add to repository");
        addButton.addActionListener(this::addGraph);

        controlPanel.add(addButton);

        JButton reportButton = new JButton ("Report HTML");
        reportButton.addActionListener(this::reportHTML);

        controlPanel.add(reportButton);
        // add everything to this form
        String title = "<html><i><font color='blue'>" +
                "Add graph" + "</font></i></hmtl>";

        JButton openButton = new JButton ("Open Graph");
        openButton.addActionListener (this::openGraph);
        controlPanel.add(openButton);

        JButton openByChooseButton = new JButton ("Choose a file for open");
        openByChooseButton.addActionListener(this::openByChoose);
        controlPanel.add(openByChooseButton);

        JButton tableButton = new JButton ("Graph Table");
        tableButton.addActionListener(this::tableGraph);
        controlPanel.add(tableButton);


        this.setBorder(BorderFactory.createTitledBorder(title));
        this.add(textBoxesPanel);
        this.add(characteristicsPanel);
        this.add(controlPanel);
//        Catalog catalog = new Catalog("graphs");
//        frame.setCatalog(catalog);
    }



    private void addGraph(ActionEvent e) {
        System.out.println("Buton apăsat!");
        frame.getList().addGraph("[Nume]: " + nameField.getText() +
                " [Def file]: " + defPathField.getText() + " [Img file]: " + imgPathField.getText() +
                " [Type]: " + graphTypeList.getSelectedItem() + " [Num of vertices]: " +
                verticesField.getValue() + " [Num of edges]: " + edgesField.getValue());
        frame.getCatalog().add (new Graph(nameField.getText(), defPathField.getText(), imgPathField.getText()));
    }

    private void reportHTML(ActionEvent e) {
        Command exec=new ReportHTMLCommand();
        String words[]={"report"};
        exec.execute(words, frame.getCatalog());


    }

    private void openGraph(ActionEvent e){
        Command exec=new OpenCommand();
        String open[]={"open", imgPathField.getText()};
        exec.execute(open, frame.getCatalog());
    }

    private void tableGraph(ActionEvent e){
        JFrame frame2 = new JFrame("Graph Table");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Create and set up the content pane.
        GraphTable newContentPane = new GraphTable(frame.getCatalog(), nameField, defPathField, imgPathField, graphTypeList, verticesField, edgesField);
        newContentPane.setOpaque(true); //content panes must be opaque
        frame2.setContentPane(newContentPane);

        //Display the window.
        frame2.pack();
        frame2.setVisible(true);
    }

    private void openByChoose(ActionEvent e)
    {
        JFrame frames = new JFrame("File Chooser");
        frames.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Add content to the window.
        frames.add(new FileChooser(frame.getCatalog()));

        //Display the window.
        frames.pack();
        frames.setVisible(true);
    }
}