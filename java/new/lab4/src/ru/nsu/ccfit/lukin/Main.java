package ru.nsu.ccfit.lukin;

import ru.nsu.ccfit.lukin.dealer.Dealer;
import ru.nsu.ccfit.lukin.factory.AutoFactory;
import ru.nsu.ccfit.lukin.products.Accessory;
import ru.nsu.ccfit.lukin.products.Body;
import ru.nsu.ccfit.lukin.products.Motor;
import ru.nsu.ccfit.lukin.provider.AccessoryProvider;
import ru.nsu.ccfit.lukin.provider.BodyProvider;
import ru.nsu.ccfit.lukin.provider.MotorProvider;
import ru.nsu.ccfit.lukin.storage.AutoStorage;
import ru.nsu.ccfit.lukin.storage.Storage;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.IOException;
import java.util.Properties;

public class Main extends JFrame {

    private final JSlider autoSpeed;
    private final JSlider bodySpeed;
    private final JSlider motorSpeed;
    private final JSlider accessorySpeed;
    private final JSlider dealersSpeed;

    private static final long bodyStorageSize;
    private static final long motorStorageSize;
    private static final long accessoryStorageSize;
    private static final long autoStorageSize;
    private static final int accessoryProviders;
    private static final int dealersCount;

    static {
        Properties props = new Properties();
        try {
            props.load(Main.class.getResourceAsStream("production.prop"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        bodyStorageSize = Long.parseLong(props.getProperty("BodyStorageSize"));
        motorStorageSize = Long.parseLong(props.getProperty("MotorStorageSize"));
        accessoryStorageSize = Long.parseLong(props.getProperty("AccessoryStorageSize"));
        autoStorageSize = Long.parseLong(props.getProperty("AutoStorageSize"));
        accessoryProviders = Integer.parseInt(props.getProperty("AccessoryProviders"));
        dealersCount = Integer.parseInt(props.getProperty("Dealers"));
    }

    private final JLabel autoLabel;
    private final JLabel bodyLabel;
    private final JLabel motorLabel;
    private final JLabel accessoryLabel;
    private final Timer timer;


    private AccessoryProvider accessoryProvider;
    private MotorProvider motorProvider;
    private BodyProvider bodyProvider;
    private AutoFactory autoFactory;
    private Thread[] threads;
    private Dealer[] dealers;
    private Storage bodyStorage;
    private Storage motorStorage;
    private Storage accessoryStorage;
    private AutoStorage autoStorage;

    public static void main(String[] args) {
        Main frame = new Main();
    }

    private void start() {
        threads = new Thread[4 + dealersCount];
        bodyStorage = new Storage<>(bodyStorageSize);
        motorStorage= new Storage<>(motorStorageSize);
        accessoryStorage = new Storage<>(accessoryStorageSize);
        autoStorage = new AutoStorage(autoStorageSize);
        autoFactory = new AutoFactory(autoStorage, bodyStorage, motorStorage,
                                                    accessoryStorage, autoSpeed.getValue());
        bodyProvider = new BodyProvider(bodyStorage, bodySpeed.getValue());
        motorProvider = new MotorProvider(motorStorage, motorSpeed.getValue());
        accessoryProvider = new AccessoryProvider(accessoryStorage,
                                                   accessorySpeed.getValue(), accessoryProviders);
        dealers = new Dealer[dealersCount];
        for (int i = 0; i < dealersCount; ++i) {
            dealers[i] = new Dealer(autoStorage, dealersSpeed.getValue());
        }
        threads[0] = new Thread(autoFactory);
        threads[1] = new Thread(bodyProvider);
        threads[2] = new Thread(motorProvider);
        threads[3] = new Thread(accessoryProvider);
        for (int i = 0; i < dealersCount; ++i) {
            threads[i + 4] = new Thread(dealers[i]);
        }
        for (int i = 0; i < 4 + dealersCount; ++i) {
            threads[i].start();
        }
        timer.start();
    }

    private Main() {
        super("Factory");
//        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        addWindowListener(new WindowListener() {
                              public void windowOpened(WindowEvent windowEvent) {}
                              public void windowClosing(WindowEvent event) {
                                  if (timer != null)
                                      timer.stop();
                                  if (autoFactory != null)
                                      autoFactory.stop();
                                  if (motorProvider != null)
                                      motorProvider.stop();
                                  if (bodyProvider != null)
                                      bodyProvider.stop();
                                  if (accessoryProvider != null)
                                      accessoryProvider.stop();
                                  if (dealers != null)
                                      for (Dealer dealer : dealers)
                                          if (dealer != null)
                                              dealer.stop();
                                  if (threads != null)
                                      for (Thread thread: threads)
                                          if (thread != null)
                                              try {
                                                  thread.interrupt();
                                                  thread.join();
                                              } catch (InterruptedException ignored) {}
                                  System.exit(0);
                              }
                              public void windowClosed(WindowEvent windowEvent) {}
                              public void windowIconified(WindowEvent windowEvent) {}
                              public void windowDeiconified(WindowEvent windowEvent) {}
                              public void windowActivated(WindowEvent windowEvent) {}
                              public void windowDeactivated(WindowEvent windowEvent) {}
                          });
        setLayout(new GridBagLayout());
        autoSpeed = new JSlider();
        autoSpeed.setMinimum(0);
        autoSpeed.setMaximum(10000);
        autoSpeed.setValue(1000);
        bodySpeed = new JSlider();
        bodySpeed.setMinimum(0);
        bodySpeed.setMaximum(10000);
        bodySpeed.setValue(1000);
        motorSpeed = new JSlider();
        motorSpeed.setMinimum(0);
        motorSpeed.setMaximum(10000);
        motorSpeed.setValue(1000);
        accessorySpeed = new JSlider();
        accessorySpeed.setMinimum(0);
        accessorySpeed.setMaximum(10000);
        accessorySpeed.setValue(1000);
        dealersSpeed = new JSlider();
        dealersSpeed.setMinimum(0);
        dealersSpeed.setMaximum(10000);
        dealersSpeed.setValue(1000);
        JButton start = new JButton("start");
        start.addActionListener(actionEvent -> {
            this.remove(start);
            JButton update = new JButton("update delays");
            update.addActionListener(actionEvent1 -> this.updateDelays());
            GridBagConstraints gbc = new GridBagConstraints();
            gbc.gridx = 3;
            gbc.gridy = 1;
            gbc.fill = GridBagConstraints.HORIZONTAL;
            gbc.anchor = GridBagConstraints.CENTER;
            add(update, gbc);
            start();
            revalidate();
            repaint();
        });
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.anchor = GridBagConstraints.CENTER;
        add(start, gbc);
        gbc.gridx = 1;
        gbc.gridy = 2;
        autoLabel = new JLabel("Auto: 0:0");
        add(autoLabel, gbc);
        gbc.gridx = 2;
        bodyLabel = new JLabel("Body: 0:0");
        add(bodyLabel, gbc);
        gbc.gridx = 3;
        motorLabel = new JLabel("Engine: 0:0");
        add(motorLabel, gbc);
        gbc.gridx = 4;
        accessoryLabel = new JLabel("Accessory: 0:0");
        add(accessoryLabel, gbc);


        autoSpeed.setToolTipText("speed of auto factory");
        gbc.gridx = 1;
        gbc.gridy = 3;
        add(autoSpeed, gbc);
        bodySpeed.setToolTipText("speed of body provider");
        gbc.gridx = 2;
        add(bodySpeed, gbc);
        motorSpeed.setToolTipText("speed of engine provider");
        gbc.gridx = 3;
        add(motorSpeed, gbc);
        accessorySpeed.setToolTipText("speed of accessory providers");
        gbc.gridx = 4;
        add(accessorySpeed, gbc);
        dealersSpeed.setToolTipText("speed of dealers");
        gbc.gridx = 5;
        add(dealersSpeed, gbc);
        pack();
        timer = new Timer(100, actionEvent -> {
            autoLabel.setText("Auto: " + autoStorage.getProducts() + ":" + autoFactory.getProduced());
            bodyLabel.setText("Body: "+ bodyStorage.getProducts() + ":" + bodyProvider.getTotal());
            motorLabel.setText("Engine: "+ motorStorage.getProducts() + ":" + motorProvider.getTotal());
            accessoryLabel.setText("Accessory: "+ accessoryStorage.getProducts() + ":" + accessoryProvider.getTotal());
//            repaint();
        });
        setVisible(true);
    }

    private void updateDelays() {
        autoFactory.setDelay(autoSpeed.getValue());
        bodyProvider.setDelay(bodySpeed.getValue());
        motorProvider.setDelay(motorProvider.getDelay());
        accessoryProvider.setDelay(accessorySpeed.getValue());
        for (Dealer dealer : dealers) {
            dealer.setDelay(dealersSpeed.getValue());
        }
    }
}
