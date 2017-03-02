package sapper;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

/**
 * Created by dzs on 14.02.17.
 */
public class GUI extends JFrame implements Runnable {
    private JPanel currentPanel;
    static int prefferedHeidht = 9;
    static int prefferedWidth = 9;
    private class startPanel extends JPanel {
        JButton start;
        JSpinner height;
        JSpinner width;
        JTextField nickname;
        JSlider minesPercent;

        private startPanel() {
            super(new GridBagLayout());
            height = new JSpinner(new SpinnerNumberModel(prefferedHeidht, 5, 100, 1));
            width = new JSpinner(new SpinnerNumberModel(prefferedWidth, 5, 100, 1));
            start = new JButton("start");
            GridBagConstraints gbc = new GridBagConstraints();
            gbc.gridx = 2;
            gbc.gridy = 1;
            gbc.fill = GridBagConstraints.HORIZONTAL;
            add(start, gbc);
            width.setToolTipText("width");
            gbc = new GridBagConstraints();
            gbc.gridx = 1;
            gbc.gridy = 1;
            gbc.anchor = GridBagConstraints.WEST;
            gbc.fill = GridBagConstraints.BOTH;
            add(width, gbc);
            height.setToolTipText("height");
            gbc = new GridBagConstraints();
            gbc.gridx = 0;
            gbc.gridy = 1;
            gbc.anchor = GridBagConstraints.WEST;
            gbc.fill = GridBagConstraints.BOTH;
            add(height, gbc);
            nickname = new JTextField();
            nickname.setHorizontalAlignment(0);
            nickname.setText("guest");
            nickname.setToolTipText("nickname for leadboard");
            gbc = new GridBagConstraints();
            gbc.gridx = 0;
            gbc.gridy = 0;
            gbc.gridwidth = 3;
            gbc.anchor = GridBagConstraints.WEST;
            gbc.fill = GridBagConstraints.HORIZONTAL;
            add(nickname, gbc);
            minesPercent = new JSlider();
            minesPercent.setMaximum(50);
            minesPercent.setMinimum(1);
            minesPercent.setValue(13);
            gbc = new GridBagConstraints();
            gbc.gridx = 0;
            gbc.gridy = 2;
            gbc.gridwidth = 3;
            gbc.anchor = GridBagConstraints.WEST;
            gbc.fill = GridBagConstraints.HORIZONTAL;
            add(minesPercent, gbc);
            start.addActionListener(actionEvent -> onStart());
            start.registerKeyboardAction(e -> onStart(),
                    KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0),
                    JComponent.WHEN_IN_FOCUSED_WINDOW);
        }
        private void onStart() {
            int rows = (int) height.getValue();
            int colons = (int) width.getValue();
            prefferedHeidht = rows;
            prefferedWidth = colons;
            int mines = rows * colons * minesPercent.getValue() / 100;
            startGame(rows, colons, mines, nickname.getText());
        }
    }

    private class gamePanel extends JPanel {
        private Model model;
        private Game game;
        public gamePanel(int rows, int colons, int mines, String nickname) {
            super(new GridLayout(rows, colons));
            model = new Model(rows, colons, mines);
            game = new Game(model);
            for (int row = 0; row < rows; ++row) {
                for (int colon = 0; colon < colons; ++colon) {
                    JButton button = new JButton();
                    button.addMouseListener(new ButtonListener(row, colon));
                    button.setPreferredSize(new Dimension(42, 42));
                    add(button);
                }
            }
            updateAll();
        }
        private class ButtonListener implements MouseListener {
            private int row;
            private int colon;
            public ButtonListener(int row, int colon) {
                this.row = row;
                this.colon = colon;
            }
            public void mouseClicked(MouseEvent mouseEvent) {}
            public void mousePressed(MouseEvent mouseEvent) {
                if (mouseEvent.getButton() == MouseEvent.BUTTON1) {
                    game.touch(row, colon);
                    updateFreePointsFrom(row, colon);
                } else if (mouseEvent.getButton() == MouseEvent.BUTTON3) {
                    game.mark(row, colon);
                    updateAt(row, colon);
                }
            }
            public void mouseReleased(MouseEvent mouseEvent) {}
            public void mouseEntered(MouseEvent mouseEvent) {}
            public void mouseExited(MouseEvent mouseEvent) {}
        }
        private void updateAll() {
            final int rows = model.getHeight();
            final int colons = model.getWidth();
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < colons; ++j) {
                    updateAt(i, j);
                }
            }
        }
        private void updateFreePointsFrom(int row, int colon) {
            int range = 1;
            boolean haveZero = model.getPointScore(row, colon) == 0;
            int rows = model.getHeight();
            int colons = model.getWidth();
            updateAt(row, colon);
            while(haveZero) {
                haveZero = false;
                if(colon - range >= 0) {
                    for (int i = row - range; i <= row + range; ++i) {
                        if(i >= 0 && i < rows) {
                            haveZero = haveZero || model.getPointScore(i, colon - range) == 0;
                            updateAt(i, colon - range);
                        }
                    }
                }
                if (colon + range < colons) {
                    for (int i = row - range; i <= row + range; ++i) {
                        if(i >= 0 && i < rows) {
                            haveZero = haveZero || model.getPointScore(i, colon + range) == 0;
                            updateAt(i, colon + range);
                        }
                    }
                }
                if (row - range >= 0) {
                    for(int i = colon - range + 1; i < colon + range; ++i) {
                        if(i >= 0 && i < colons) {
                            haveZero = haveZero || model.getPointScore(row - range, i) == 0;
                            updateAt(row - range, i);
                        }
                    }
                }
                if (row + range < rows) {
                    for(int i = colon - range + 1; i < colon + range; ++i) {
                        if(i >= 0 && i < colons) {
                            haveZero = haveZero || model.getPointScore(row + range, i) == 0;
                            updateAt(row + range, i);
                        }
                    }
                }
                ++range;
            }
        }
        private void updateAt(int row, int colon) {
            Model.Point point = model.getPoint(row, colon);
            JButton button = ((JButton)getComponent(row * model.getHeight() + colon));
            switch(point.getNote()) {
                case KNOWN:
                    switch (point.getState()) {
                        case FREE:
                            button.setBackground(primary4);
                            String pointScore = Integer.toString(model.getPointScore(row, colon));
                            button.setToolTipText(pointScore);
                            button.setText(pointScore);
                            break;
                        case MINED:
                            button.setBackground(complement0);
                            button.setToolTipText("Mine");
                            break;
                    }
                    break;
                case UNKNOWN:
                    button.setBackground(primary1);
                    button.setToolTipText("Unknown");
                    break;
                case UNKNOWN_FLAG:
                    button.setBackground(complement4);
                    button.setToolTipText("Flag");
                    break;
                case UNKNOWN_QUESTION:
                    button.setBackground(secondaryB4);
                    button.setToolTipText("Question");
                    break;
            }
            button.revalidate();
            button.repaint();
        }
    }

    public GUI() {
        super("Sapper");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        createMenu();
    }

    public void createMenu() {
        JMenuBar menu = new JMenuBar();
        menu.setOpaque(true);
        menu.setBackground(secondaryA3);
        JMenu menuFile = new JMenu("File");
        JMenuItem menuFileNewGame = new JMenuItem("new game");
        menuFileNewGame.addActionListener(actionEvent -> startMainMenu());
        menuFile.add(menuFileNewGame);
        JMenuItem menuFileClose = new JMenuItem("close");
        menuFileClose.addActionListener(actionEvent -> System.exit(0));
        menuFile.add(menuFileClose);
        menu.add(menuFile);
        setJMenuBar(menu);
    }

    public void run() {
        currentPanel = new startPanel();
        add(currentPanel);
        pack();
        setVisible(true);
    }

    public void startMainMenu() {
        remove(currentPanel);
        currentPanel = new startPanel();
        add(currentPanel);
        pack();
        setVisible(true);
    }

    private void startGame(int rows, int colons, int mines, String nickname) {
        remove(currentPanel);
        currentPanel = new gamePanel(rows, colons, mines, nickname);
        add(currentPanel);
        pack();
        setVisible(true);
    }

    private Color primary0 = new Color(4, 129, 158); // 0
    private Color primary1 = new Color(32, 102, 118);
    private Color primary2 = new Color(1, 83, 103);
    private Color primary3 = new Color(56, 178, 206);
    private Color primary4 = new Color(96, 185, 206);
    private Color secondaryA0 = new Color(17, 66, 170); // A0
    private Color secondaryA1 = new Color(42, 69, 128);
    private Color secondaryA2 = new Color(6, 39, 111);
    private Color secondaryA3 = new Color(69, 115, 213);
    private Color secondaryA4 = new Color(108, 141, 213);
    private Color secondaryB0 = new Color(0, 180, 84);
    private Color secondaryB1 = new Color(34, 135, 81);
    private Color secondaryB2 = new Color(0, 117, 54); // B2
    private Color secondaryB3 = new Color(54, 218, 130);
    private Color secondaryB4 = new Color(98, 218, 154);
    private Color complement0 = new Color(255, 127, 0);
    private Color complement1 = new Color(191, 119, 48);
    private Color complement2 = new Color(166, 82, 0); // 2
    private Color complement3 = new Color(255, 159, 64);
    private Color complement4 = new Color(255, 184, 115);
}
