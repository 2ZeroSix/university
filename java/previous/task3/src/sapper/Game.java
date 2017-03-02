package sapper;

import static sapper.Model.*;

/**
 * Created by dzs on 14.02.17.
 */
public class Game {
    private Model model;

    private void init(Model fld) {
        model = fld;
    }
    public Game(Model fld) {
        init(fld);
    }
    public Game() { init(new Model()); }

    public boolean touch(int row, int colon) {
        if (model.getStatus() == Status.ALIVE) {
            Model.Point p = model.getPoint(row, colon);
            if (p.getNote() == Point.Note.UNKNOWN) {
                p.setNote(Point.Note.KNOWN);
                if (p.getState() == Point.State.MINED) {
                    model.setStatus(Status.DEAD);
                    return false;
                } else if (model.getPointScore(row, colon) == 0) {
                    touchSuccessors(row, colon);
                }
            }
        }
        return true;
    }

    private void touchSuccessors(int row, int colon) {
        for (int i = row - 1; i <= row + 1; ++i) {
            if (i >= 0 && i < model.getHeight())
            for (int j = colon - 1; j <= colon + 1; ++j) {
                if (j >= 0 && j < model.getWidth())
                if (!touch(i, j)) {
                    throw new UnexpectedBehaviorException("score == 0, but it's not");
                }
            }
        }
    }

    public void mark(int row, int colon) {
        if (model.getStatus() == Status.ALIVE) {
            Model.Point p = model.getPoint(row, colon);
            Point.Note note = p.getNote();
            switch(note) {
                case UNKNOWN:
                    p.setNote(Point.Note.UNKNOWN_FLAG);
                    break;
                case UNKNOWN_FLAG:
                    p.setNote(Point.Note.UNKNOWN_QUESTION);
                    break;
                case UNKNOWN_QUESTION:
                    p.setNote(Point.Note.UNKNOWN);
                    break;
                default:
                    break;
            }
        }
    }

}