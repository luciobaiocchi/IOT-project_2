package view;

import javax.swing.*;
import javax.swing.border.MatteBorder;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;
import controller.Controller;

public class History extends JPanel {
    private JEditorPane statisticsPane; // Changed to JEditorPane

    public History(final Controller controller) {
        String statsHtml = "<html><body style='font-family:sans-serif; padding:10px;'>" +
                "<h1>HISTORY</h1>" +
                "<table style='width:100%;' border='3' cellpadding='5' cellspacing='0'>" +
                "<tr><th>DATE</th><th>TIME</th><th>PERCENTAGE</th></tr>" +
                "<tr><td> " + "controller.getHistory().getFirst().getFirst()" +  "</td><td>12:00:00</td><td>100%</td></tr>" +
                "</body></html>";

        //statisticsPane.setText(statsHtml);
    }
}
