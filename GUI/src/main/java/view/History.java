package view;

import javax.swing.*;
import javax.swing.border.MatteBorder;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;
import controller.Controller;

public class History extends JPanel {
    private JEditorPane statisticsPane; // Changed to JEditorPane
    private GraficoPanel graficoPanel;

    public History(final Controller controller) {
        statisticsPane = new JEditorPane(); // Changed to JEditorPane
        graficoPanel = new GraficoPanel();
        this.add(graficoPanel);
        this.setBackground(Color.darkGray);
    }
}
