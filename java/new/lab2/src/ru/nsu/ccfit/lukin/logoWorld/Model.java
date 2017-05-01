package ru.nsu.ccfit.lukin.logoWorld;

import java.util.Arrays;

/**
 * logoworld model (model in MVC)
 */
public class Model {
    /**
     * point in logoworld model
     */
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
    private int currentRow;
    private int currentColon;
    private boolean drawable;
    private Point[][] map;

    /**
     * init model
     * @param rows
     * @param colons
     * @param currentRow
     * @param currentColon
     */
    public Model(int rows, int colons, int currentRow, int currentColon) {
        this.rows = rows;
        this.colons = colons;
        this.currentRow = currentRow;
        this.currentColon = currentColon;
        map = new Point[rows][colons];
        for (int row = 0; row < rows; ++row) {
            for (int colon = 0; colon < colons; ++colon) {
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

    public int getCurrentRow() {
        return currentRow;
    }

    public synchronized void setCurrentRow(int row) {
        this.currentRow = row;
    }

    public int getCurrentColon() {
        return currentColon;
    }

    public synchronized void setCurrentColon(int currentColon) {
        this.currentColon = currentColon;
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
        return row == this.currentRow && colon == this.currentColon ? Point.CURRENT : map[row][colon];
    }
    public void shadePoint(int row, int colon) {
        if (drawable) map[row][colon] = Point.SHADED;
    }
}
