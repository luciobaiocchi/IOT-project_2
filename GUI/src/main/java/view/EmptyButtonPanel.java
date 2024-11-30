package view;

import javax.swing.*;
import javax.swing.border.MatteBorder;
import java.awt.*;
import utilities.ScreenSize;
import controller.Controller;

public class EmptyButtonPanel extends JPanel {
    private JButton button = buildButton();

    public EmptyButtonPanel(final Controller controller) {
        add(button);
        setBackground(Color.LIGHT_GRAY);
        setBorder(new MatteBorder(2, 5, 5, 5, Color.black));
        button.addActionListener(e -> {
            System.out.println("Emptying container");
            controller.empty();
        });
    }

    private JButton buildButton() {
        JButton button = new JButton("EMPTY");

        button.setFont(new Font("Arial", Font.BOLD, 24));
        button.setBackground(Color.red);
        button.setForeground(Color.BLACK);
        button.setBorder(new MatteBorder(5, 5, 5, 5, Color.black));
        button.setFocusPainted(false);
        setLayout(new GridBagLayout());
        add(button, new GridBagConstraints());
        button.setPreferredSize(new Dimension(
                ScreenSize.getWidth()/3,
                ScreenSize.getHeight()/5));
        return button;
    }
}
