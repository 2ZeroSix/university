package ru.nsu.ccfit.lukin.logWorld;

/**
 * Created by dzs on 22.03.17.
 */
public class Model {
    public enum Point {
        EMPTY('_'),
        SHADED('#'),
        CURRENT('*');
        char ch;
        Point(char c) {
            ch = c;
        }

        @Override
        public String toString() {
            return String.valueOf(ch);
        }
        public char toChar() {
            return ch;
        }
    }
    private int rows;
    private int colons;
    private int row;
    private int colon;
    private boolean drawable;
    private Point[][] map;
    public Model(int rows, int colons, int row, int colon) {
        this.rows = rows;
        this.colons = colons;
        this.row = row;
        this.colon = colon;
        map = new Point[rows][colons];
        for (row = 0; row < rows; ++row) {
            for (colon = 0; colon < colons; ++colon) {
                map[row][colon] = Point.EMPTY;
            }
        }
    }

    public int getRows() {
        return rows;
    }

    public synchronized void setRows(int rows) {
        this.rows = rows;
    }

    public int getColons() {
        return colons;
    }

    public synchronized void setColons(int colons) {
        this.colons = colons;
    }

    public int getRow() {
        return row;
    }

    public synchronized void setRow(int row) {
        this.row = row;
    }

    public int getColon() {
        return colon;
    }

    public synchronized void setColon(int colon) {
        this.colon = colon;
    }

    public boolean isDrawable() {
        return drawable;
    }

    public synchronized void setDrawable(boolean drawable) {
        this.drawable = drawable;
    }

    public synchronized void setMap(Point[][] map) {
        this.map = map;
    }

    public Point getPoint(int row, int colon) {
        return row == this.row && colon == this.colon ? Point.CURRENT : map[row][colon];
    }
    public void setPoint(int row, int colon, Point p) {
        if (drawable) map[row][colon] = p;
    }
}
