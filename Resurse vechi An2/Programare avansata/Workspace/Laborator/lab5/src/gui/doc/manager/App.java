package gui.doc.manager;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileNotFoundException;
import java.io.IOException;

public class App {
    private JButton loadButton;
    private JButton saveButton;
    private JPanel mainPanel;
    private JLabel docTitle;
    private JTextField docName;
    private JTextField pathLocation;
    private JLabel pathTitle;
    private JSpinner spinner1;
    private JButton addToReposityButton;
    private JList list1;

    public App() {
        Catalog catalog = new Catalog();

        loadButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null,pathLocation);   q
            }
        });
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null,"Save item!");
                try {
                    catalog.save("D:\\Workspace\\Windows\\Desktop\\Projects\\PA\\Laborator\\lab5\\resources\\catalog.dat");
                } catch (IOException e1) {
                    e1.printStackTrace();
                }
            }
        });
        addToReposityButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    catalog.add(new Book(docName.getText(), pathLocation.getText(), (Integer) spinner1.getValue(), "Donald E. Knuth"));
                } catch (Document.YearException e1) {
                    e1.printStackTrace();
                } catch (FileNotFoundException e1) {
                    e1.printStackTrace();
                }
                JOptionPane.showMessageDialog(null,"Publish item!");
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("App");
        frame.setContentPane(new App().mainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }

    private void createUIComponents() {
        // TODO: place custom component creation code here
    }
}
