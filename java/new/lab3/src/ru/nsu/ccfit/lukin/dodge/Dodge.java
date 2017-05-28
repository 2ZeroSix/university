package ru.nsu.ccfit.lukin.dodge;

import javax.swing.*;
import java.awt.*;

/**
 * Created by dzs on 09.05.17.
 */
public class Dodge extends JFrame implements Runnable {
    private JPanel currentPanel;
    private Properties properties = new Properties();
    private JPanel startPanel = new JPanel() {{
        setLayout(new GridBagLayout());
        JTextField textField = new JTextField();
        textField.setHorizontalAlignment(0);
        textField.setText("guest");
        textField.setDisabledTextColor(Color.GRAY);
        textField.setDisabledTextColor(Color.BLACK);
        textField.setToolTipText("nickname for leaderboard");
        add(textField, new GridBagConstraints(1, 1, 1, 1, 1, 0,
                GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(5, 5, 5, 5), 0, 0));

        JButton start = new JButton("START");
        start.addActionListener(str -> {
            properties.name = textField.getText();
            startGame();
        });
        start.setFocusable(false);
        add(start, new GridBagConstraints(1, 2, 1, 1, 0, 0,
                GridBagConstraints.CENTER, GridBagConstraints.CENTER,
                new Insets(5, 5, 5, 5), 0, 0));
    }};

    private static class Properties {
        String name;
        int sizeX = 480;
        int sizeY = 270;
        public Controller.Difficulty difficulty = Controller.Difficulty.MEDIUM;
    }

    public Dodge() {
        super("Dodge");
        setMenuBar();
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        changeCurrentPanel(startPanel);
    }

    private void setMenuBar() {
        MenuBar menuBar = new MenuBar();
        Menu file = new Menu("File");
        MenuItem newGame = new MenuItem("New game");
        newGame.addActionListener(str -> changeCurrentPanel(startPanel));
        file.add(newGame);
        MenuItem exit = new MenuItem("Exit");
        exit.addActionListener(str -> System.exit(0));
        file.add(exit);
        menuBar.add(file);
        setMenuBar(menuBar);
    }

    private void changeCurrentPanel(JPanel panel) {
        if (getContentPane() instanceof View)
            ((View)getContentPane()).stop();
        panel.setPreferredSize(new Dimension(properties.sizeX, properties.sizeY));
        setContentPane(panel);
        pack();
        repaint();
    }

    private void startGame() {
        Model model;
        try {
            model = new Model();
            Controller controller = new Controller(model, properties.difficulty);
            View view = new View(controller);
            changeCurrentPanel(view);
            view.start();
        } catch (DodgeException e) {
            JOptionPane.showMessageDialog( this,
                    e.getLocalizedMessage(),
                    "FAIL: can't start game",
                    JOptionPane.PLAIN_MESSAGE);
        }
    }

    public void run() {
        setVisible(true);
    }
}
