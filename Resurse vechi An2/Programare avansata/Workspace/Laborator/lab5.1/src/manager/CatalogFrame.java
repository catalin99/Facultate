/**
 * @author Birsan Ioana (cas. Amariei)
 * @author Gensthaler Octavian
 */

package manager;

import javax.swing.*;
import java.awt.*;

public class CatalogFrame extends JFrame {
    DocumentForm form;
    CatalogList list;
    ControlPanel control;

    public CatalogFrame() {
        super("Visual Document Manager");
        init();
        addComponents();
        this.pack();
    }

    private void init() {
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        form = new DocumentForm(this);
        list = new CatalogList();
        control = new ControlPanel(this);
    }

    private void addComponents(){
        add(form, BorderLayout.NORTH);
        add(list, BorderLayout.CENTER);
        add(control, BorderLayout.SOUTH);
    }

}