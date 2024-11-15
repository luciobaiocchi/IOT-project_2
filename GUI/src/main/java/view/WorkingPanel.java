package view;

import utilities.ScreenSize;
import javax.swing.*;
import javax.swing.border.MatteBorder;
import java.awt.*;
import java.util.Objects;
import controller.Controller;

public class WorkingPanel extends JPanel {

    private final JProgressBar progressBar = new JProgressBar();
    private final JLabel imageLabel = new JLabel();

    public WorkingPanel(final Controller controller) {
        setLayout(new BorderLayout());
        setBorder(new MatteBorder(5, 5, 3, 5, Color.black));
        setBackground(Color.LIGHT_GRAY);

        setOpaque(true);


        // Carica e ridimensiona l'immagine in base alle dimensioni dello schermo
        ImageIcon originalIcon = new ImageIcon(Objects
                .requireNonNull(ClassLoader
                        .getSystemClassLoader().getResource("Battery.png")));
        Dimension screenSize = ScreenSize.getSize();


        // Calcola la dimensione ridimensionata, es. 50% della larghezza dello schermo
        int scaledWidth = screenSize.width / 8;
        int scaledHeight = scaledWidth * originalIcon.getIconHeight() / originalIcon.getIconWidth();
        Image scaledImage = originalIcon.getImage().getScaledInstance(scaledWidth, scaledHeight, Image.SCALE_SMOOTH);
        ImageIcon scaledIcon = new ImageIcon(scaledImage);

        imageLabel.setOpaque(true);
        imageLabel.setBackground(Color.LIGHT_GRAY);


        imageLabel.setIcon(scaledIcon);
        imageLabel.setLayout(new GridBagLayout()); // Imposta il layout per centrare la progressBar

        scaledWidth -= 100;
        scaledHeight -= 50;


        // Configura la progressBar per avere la stessa grandezza dell'immagine
        progressBar.setOrientation(JProgressBar.VERTICAL);
        progressBar.setPreferredSize(new Dimension(scaledWidth, scaledHeight));
        progressBar.setMinimumSize(new Dimension(scaledWidth, scaledHeight));
        progressBar.setMaximumSize(new Dimension(scaledWidth, scaledHeight));
        progressBar.setStringPainted(true);


        imageLabel.add(progressBar, new GridBagConstraints());

        // Crea un pannello centrale per centrare l'immagine e la progressBar
        JPanel centerPanel = new JPanel(new GridBagLayout());
        centerPanel.add(imageLabel, new GridBagConstraints()); // Aggiungi l'immagine centrata
        centerPanel.setBackground(Color.LIGHT_GRAY);


        // Aggiungi i componenti al pannello principale
        add(centerPanel, BorderLayout.CENTER); // Pannello centrale con immagine e progressBar centrati

        setVisible(true);
    }
}
