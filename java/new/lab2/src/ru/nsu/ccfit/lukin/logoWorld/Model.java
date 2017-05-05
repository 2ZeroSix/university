package ru.nsu.ccfit.lukin.logoWorld;

import java.util.stream.Stream;

/**
 * logoworld model (model in MVC)
 */
public class Model {
    /**
     * point in logoworld model
     */
    public enum Point {
        EMPTY("_"),
        SHADED("#"),
        CURRENT("*");
        String str;
        Point(String c) {
            str = c;
        }

        @Override
        public String toString() {
            return str;
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
     * @param rows width of map
     * @param colons height of map
     * @param currentRow start row
     * @param currentColon start colon
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

    /**
     * @return width of map
     */
    public int getRows() {
        return rows;
    }

    /**
     * @return height of map
     */
    public int getColons() {
        return colons;
    }

    /**
     * @return current row
     */
    public int getCurrentRow() {
        return currentRow;
    }

    /**
     * @param currentRow new current row
     */
    public synchronized void setCurrentRow(int currentRow) {
        this.currentRow = currentRow;
    }

    /**
     * @return current colon
     */
    public int getCurrentColon() {
        return currentColon;
    }

    /**
     * @param currentColon new current colon
     */
    public synchronized void setCurrentColon(int currentColon) {
        this.currentColon = currentColon;
    }

    /**
     * @return true if map is drawable, else false
     */
    public boolean isDrawable() {
        return drawable;
    }

    /**
     * @param drawable new state of drawable feature
     */
    public synchronized void setDrawable(boolean drawable) {
        this.drawable = drawable;
    }

    /**
     * @param row row of point
     * @param colon colon of point
     * @return Point on position (row, colon)
     */
    public Point getPoint(int row, int colon) {
        return row == this.currentRow && colon == this.currentColon ? Point.CURRENT : map[row][colon];
    }

    /**
     * shades Point at position (row, colon)
     * @param row row of point
     * @param colon colon of point
     */
    public void shadePoint(int row, int colon) {
        if (drawable) map[row][colon] = Point.SHADED;
    }
}
