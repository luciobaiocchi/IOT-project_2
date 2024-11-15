package view;

import controller.Controller;
import utilities.ScreenSize;
import javax.swing.*;
import javax.swing.border.MatteBorder;
import java.awt.*;
import view.History;

public class MainWindow extends JFrame {
    private WorkingPanel workingPanel;
    private ButtonPanel buttonPanel;
    private History history;


    private JPanel mainPanel;

    public MainWindow(final Controller controller) {
        workingPanel = new WorkingPanel(controller);
        buttonPanel = new ButtonPanel(controller);
        history = new History(controller);
        mainPanel = buildMainPanel();

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        double width = ScreenSize.getWidth() / 1.2;
        double height = ScreenSize.getHeight() / 1.2;
        setSize((int) width,(int) height);

        setLocationRelativeTo(null);

        add(mainPanel);
        setVisible(true);

    }

    private JPanel buildMainPanel() {
        JPanel mainPanel = new JPanel();

        mainPanel.setLayout(new GridLayout(2, 2));
        mainPanel.setBackground(Color.darkGray);
        //mainPanel.setBorder(new MatteBorder(3, 3, 3, 3, Color.BLACK));

        mainPanel.add(workingPanel);
        mainPanel.add(history);
        mainPanel.add(buttonPanel);
        mainPanel.add(new JPanel());

        return mainPanel;

    }


}
