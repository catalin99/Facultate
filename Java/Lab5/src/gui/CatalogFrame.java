package gui;

import entity.Catalog;

import javax.swing.*;
import java.awt.*;

public class CatalogFrame extends JFrame {
    private GraphForm form;
    private CatalogList list;
    private ControlPanel control;
    private Catalog catalog=new Catalog("Graphs");

    public CatalogFrame() {
        super("Visual Graph Manager");
        form = new GraphForm(this);
        setList(new CatalogList());
        control = new ControlPanel(catalog);
        init();
    }

    private void init() {
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.add(form, BorderLayout.NORTH);
        this.add(getList(), BorderLayout.CENTER);
        this.add(control, BorderLayout.SOUTH);
        this.pack();
        this.setExtendedState(JFrame.MAXIMIZED_BOTH);
        this.setVisible(true);
    }

    public CatalogList getList() {
        return list;
    }

    public void setList(CatalogList list) {
        this.list = list;
    }

    public Catalog getCatalog() {
        return catalog;
    }

    public void setCatalog(Catalog catalog) {
        this.catalog = catalog;
    }
}
