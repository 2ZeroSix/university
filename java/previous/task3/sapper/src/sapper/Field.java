package sapper;

import java.lang.*;
import java.util.*;
import static java.lang.Math.*;
import java.security.SecureRandom;

public class Field {
    public enum State   {FREE, MINED}
    public enum Note    {UNKNOWN, UNKNOWN_MINE, UNKNOWN_FLAG, KNOWN}
    public class Point {
        
        private State state;
        private Note note;
        
        private void init(State st, Note nt) {
            state = st;
            note = nt;
        }
        
        public Point(State st, Note nt) {init(st, nt);}
        public Point(State st)          {init(st, Note.UNKNOWN);}
        public Point()                  {init(State.FREE, Note.UNKNOWN);}

        public State getState()         {return state;}
        public State setState(State st) {return state = st;}
        public Note getNote()           {return note;}
        public Note setNote(Note nt)    {return note = nt;}
    }
    private Point[][] map;

    private void init(int rows, int colons, int mines) {
        if (rows <= 0)
            throw new IllegalArgumentException("Bad count of rows : " + rows);
        if (colons <= 0)
            throw new IllegalArgumentException("Bad count of colons : " + colons);
        if (mines > rows*colons || mines < 0)
            throw new IllegalArgumentException("Bad count of mines : " + mines);
        generateEmptyMap(rows, colons);
        generateMines(mines);
    }
    private void generateEmptyMap(int rows, int colons) {
        map = new Point[rows][colons];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < colons; ++j) {
                map[i][j] = new Point();
            }
        }
    }
    private void generateMines(int mines) {
        int rows = map.length;
        int colons = map[0].length;
        SecureRandom rnd = new SecureRandom();
        for (int i = 0; i < mines; ++i) {
            int row =   rnd.nextInt() % rows;
            int colon = rnd.nextInt() % colons;
            while(map[row][colon].getState() == State.MINED) {
                row =   rnd.nextInt() % rows;
                colon = rnd.nextInt() % colons;
            }
            map[row][colon].setState(State.MINED);
        }
    }

    public Field(int rows, int colons, int mines) {init(rows, colons, mines);}
    public Field(int rows, int colons) {init(rows, colons, round(rows*colons*10/81));}
    public Field() {init(9, 9, 10);}

    public Point getPoint(int row, int colon) {return map[row][colon];}
    public Point setPoint(int row, int colon, Point p) {return map[row][colon] = p;}
    public int getPointScore(int row, int colon) {
        int score = 0;
        if (map[row][colon].getNote() == Note.KNOWN) {
            for (int i = row - 1; i <= row + 1; ++i) {
                for (int j = colon - 1; j <= colon + 1; ++j) {
                    if (i >= 0 && i < map.length &&
                        j >= 0 && j < map[0].length &&
                        map[i][j].getState() == State.MINED) {
                        ++score;
                    }
                }
            }
        }
        return score;
    }
}