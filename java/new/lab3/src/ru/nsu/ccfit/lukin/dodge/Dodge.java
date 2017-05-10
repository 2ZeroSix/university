package ru.nsu.ccfit.lukin.dodge;

import javax.swing.*;
import java.awt.*;

/**
 * Created by dzs on 09.05.17.
 */
public class Dodge extends JFrame implements Runnable {
    private Component currentPanel;
    private Properties properties = new Properties();

    private static class Properties {
        String name;
        int sizeX = 480;
        int sizeY = 270;
    }

    private class StartMenu extends JPanel {
        StartMenu() {
            super(new GridBagLayout());
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
            add(start, new GridBagConstraints(1, 2, 1, 1, 0, 0,
                    GridBagConstraints.CENTER, GridBagConstraints.CENTER,
                    new Insets(5, 5, 5, 5), 0, 0));
        }
    }

    public Dodge() {
        super("Dodge");
        setMenu();
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private void setMenu() {
        MenuBar menuBar = new MenuBar();
        Menu file = new Menu("File");
        MenuItem newGame = new MenuItem("New game");
        newGame.addActionListener(str -> changeCurrentComponent(new StartMenu()));
        file.add(newGame);
        MenuItem exit = new MenuItem("Exit");
        exit.addActionListener(str -> System.exit(0));
        file.add(exit);
        menuBar.add(file);
        setMenuBar(menuBar);
    }

    private void changeCurrentComponent(Component panel) {
        if (currentPanel != null) remove(currentPanel);
        currentPanel = panel;
//        currentPanel.setSize(properties.sizeX, properties.sizeY);
        currentPanel.setPreferredSize(new Dimension(properties.sizeX, properties.sizeY));
        add(currentPanel);
        pack();
        repaint();
    }

    private void startGame() {
        Model model;
        try {
            model = new Model(properties.sizeY, properties.sizeX);
            Controller controller = new Controller(model);
            changeCurrentComponent(new View(controller));
        } catch (DodgeException e) {
            JOptionPane.showMessageDialog( this,
                    e.getLocalizedMessage(),
                    "FAIL: can't start game",
                    JOptionPane.PLAIN_MESSAGE);
        }
    }


    public void run() {
        changeCurrentComponent(new StartMenu());
//        JLabel panel = null;
//        try {
//            panel = new JLabel(new RotatableImageIcon(ImageIO.read(getClass().getResource("components/abl.png"))));
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//        add(panel);
//        JLabel finalPanel = panel;
//        addMouseListener(new MouseListener() {
//            @Override
//            public void mouseClicked(MouseEvent mouseEvent) {
//                ((RotatableImageIcon)finalPanel.getIcon()).setAngle(0);
//                finalPanel.repaint();
//
//            }
//
//            @Override
//            public void mousePressed(MouseEvent mouseEvent) {
//
//            }
//
//            @Override
//            public void mouseReleased(MouseEvent mouseEvent) {
//
//            }
//
//            @Override
//            public void mouseEntered(MouseEvent mouseEvent) {
//
//            }
//
//            @Override
//            public void mouseExited(MouseEvent mouseEvent) {
//
//            }
//        });
//        pack();
        setVisible(true);
    }
}
