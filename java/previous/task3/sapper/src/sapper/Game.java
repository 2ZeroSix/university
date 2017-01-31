package sapper;

import javax.swing.*;
import java.awt.*;


public class Game implements Runnable {
    Controller controller;
    JFrame frame;
    public Game() {}
    public void run() {
        show();
    }

    private void show() {
        frame = new JFrame("Sapper");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setBackground(primary0);

        JMenuBar menu = new JMenuBar();
        menu.setOpaque(true);
        menu.setBackground(secondaryA0);
        menu.setPreferredSize(new Dimension(200, 20));
        menu.add(new JMenu("info"));
        frame.setJMenuBar(menu);


        JLabel map = new JLabel();
        map.setOpaque(true);
        map.setLayout(new GridLayout(9,9));
        map.setBackground(primary2);
        map.setPreferredSize(new Dimension(200, 180));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                map.add(new Button(i + " " + j));
            }
        }
        frame.getContentPane().add(map, BorderLayout.CENTER);


        //Display the window.
        frame.pack();
        frame.setVisible(true);
    }

    Color primary0    = new Color(  4, 129, 158); // 0
    Color primary1    = new Color( 32, 102, 118);
    Color primary2    = new Color(  1,  83, 103);
    Color primary3    = new Color( 56, 178, 206);
    Color primary4    = new Color( 96, 185, 206);
    Color secondaryA0 = new Color( 17,  66, 170); // A0
    Color secondaryA1 = new Color( 42,  69, 128);
    Color secondaryA2 = new Color(  6,  39, 111);
    Color secondaryA3 = new Color( 69, 115, 213);
    Color secondaryA4 = new Color(108, 141, 213);
    Color secondaryB0 = new Color(  0, 180,  84);
    Color secondaryB1 = new Color( 34, 135,  81);
    Color secondaryB2 = new Color(  0, 117,  54); // B2
    Color secondaryB3 = new Color( 54, 218, 130);
    Color secondaryB4 = new Color( 98, 218, 154);
    Color complement0 = new Color(255, 127,   0);
    Color complement1 = new Color(191, 119,  48);
    Color complement2 = new Color(166,  82,   0); // 2
    Color complement3 = new Color(255, 159,  64);
    Color complement4 = new Color(255, 184, 115);
}
