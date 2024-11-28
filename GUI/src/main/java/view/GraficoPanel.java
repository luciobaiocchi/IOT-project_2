package view;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.data.category.DefaultCategoryDataset;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GraficoPanel extends JPanel {
    private final DefaultCategoryDataset dataset; // Dataset condiviso

    public GraficoPanel() {
        // Crea il dataset
        dataset = new DefaultCategoryDataset();
        initDataset();

        // Crea il grafico
        JFreeChart grafico = ChartFactory.createLineChart(
                "Andamento Dinamico", // Titolo
                "Tempo", // Asse X
                "Valore", // Asse Y
                dataset
        );

        // Pannello grafico
        ChartPanel pannelloGrafico = new ChartPanel(grafico);
        pannelloGrafico.setMouseWheelEnabled(false);

        // Layout e aggiunta al pannello
        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        add(pannelloGrafico);

        // Timer per aggiornare il grafico dinamicamente
        Timer timer = new Timer(1000, new AggiornaDati());
        timer.start();
    }

    private void initDataset() {
        // Inizializza il dataset con valori iniziali
        dataset.addValue(20, "Temperatura", "10:00");
        dataset.addValue(80, "Livello", "10:00");
    }

    private class AggiornaDati implements ActionListener {
        private int counter = 1; // Contatore per i nuovi dati

        @Override
        public void actionPerformed(ActionEvent e) {
            // Genera dati simulati
            String tempo = "10:" + (counter + 10);
            double nuovaTemperatura = 20 + Math.random() * 10; // Simula la temperatura
            double nuovoLivello = 80 - Math.random() * 5;      // Simula il livello

            // Aggiorna il dataset
            dataset.addValue(nuovaTemperatura, "Temperatura", tempo);
            dataset.addValue(nuovoLivello, "Livello", tempo);

            counter++;
        }
    }
}