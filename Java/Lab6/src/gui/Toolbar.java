package gui;

import javax.swing.*;
import java.awt.*;

public class Toolbar extends JPanel {
    private final DrawingFrame frame;
    private JComboBox<String> form;
    private JComboBox<String> color;
    private TextField radiusField;
    public Toolbar(DrawingFrame frame) {
        this.frame=frame;
        init();
    }
    public void init(){
        String Fields[]={"Node", "Edge"};
        String Colors[]={"Random", "Blue", "Red", "Black", "Gray", "Yellow", "Green", "Cyan"};
        form=new JComboBox<>(Fields);
        color=new JComboBox<>(Colors);
        radiusField=new TextField("30");
        JLabel radiusLabel=new JLabel("Radius/Thickness");
        this.setLayout(new FlowLayout());
        this.add(radiusLabel);
        this.add(radiusField);
        this.add(form);
        this.add(color);


    }
    public String getRadius()
    {
        return radiusField.getText();
    }
    public String getColor() {return color.getSelectedItem().toString();}
    public String getForm() {return form.getSelectedItem().toString();}
}
