package sapper;

import java.security.SecureRandom;
import java.util.concurrent.atomic.AtomicReference;

import static java.lang.Math.round;

/**
 * Created by dzs on 14.02.17.
 */
public class Model {
    public enum Status  {ALIVE, DEAD;}
    public static class Point {

        public enum State   {FREE, MINED}
        public enum Note    {UNKNOWN, UNKNOWN_FLAG, UNKNOWN_QUESTION, KNOWN}

        private AtomicReference<State> state;
        private AtomicReference<Note> note;

        private void init(State st, Note nt) {
            state = new AtomicReference<>(st);
            note  = new AtomicReference<>(nt);
        }

        public Point(State st, Note nt) {init(st, nt);}
        public Point(State st)          {init(st, Note.UNKNOWN);}
        public Point()                  {init(State.FREE, Note.UNKNOWN);}

        public State getState()         {return state.get();}
        public void setState(State st)  {state.set(st);}
        public Note getNote()           {return note.get();}
        public void setNote(Note nt)    {note.set(nt);}
    }

    private Point[][] map;
    private Status status;
    private String nickname;
    private boolean saved;

//    initialization
    private void init(int rows, int colons, int mines, String nickname) {
        status = Status.ALIVE;
        this.nickname = nickname;
        this.saved = false;
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
            int row =   rnd.nextInt(rows);
            int colon = rnd.nextInt(colons);
            while(map[row][colon].getState() == Point.State.MINED) {
                row =   rnd.nextInt(rows);
                colon = rnd.nextInt(colons);
            }
            map[row][colon].setState(Point.State.MINED);
        }
    }

//    constructors
    public Model(int rows, int colons, int mines, String nickname) {init(rows, colons, mines,  nickname);}
    public Model(int rows, int colons, int mines) {init(rows, colons, mines,  null);}
    public Model(int rows, int colons) {init(rows, colons, round(rows*colons*10/81), null);}
    public Model() {init(9, 9, 10, null);}

//    setters & getters
    public Status getStatus() {return status;}
    public void setStatus(Status status) {this.status = status;}
    public Point getPoint(int row, int colon) {return map[row][colon];}
    public Point setPoint(int row, int colon, Point p) {return map[row][colon] = p;}
    public int getWidth() {return (map.length > 0) ? map[0].length : 0;}
    public int getHeight(){return map.length;}
    public int getPointScore(int row, int colon) {
        int score = 0;
        if (map[row][colon].getNote() == Point.Note.KNOWN) {
            for (int i = row - 1; i <= row + 1; ++i) {
                for (int j = colon - 1; j <= colon + 1; ++j) {
                    if (i >= 0 && i < map.length &&
                            j >= 0 && j < map[0].length &&
                            map[i][j].getState() == Point.State.MINED) {
                        ++score;
                    }
                }
            }
        }
        return score;
    }

//    finalization
    public void finalize() {saveInLeaderBoard();}
    public void saveInLeaderBoard() {
        if(!saved && nickname != null) {

        }
    }
}
