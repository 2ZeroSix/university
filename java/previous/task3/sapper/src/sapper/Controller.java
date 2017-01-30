package sapper;

import static Field.*;


public class Controller {
    private Field field;

    private void init(Field fld) {
        field = fld;
    }
    public Controller(Field fld) {
        init(fld);
    }
    public Controller() {
        init(new Field());
    }

    public boolean touch(int row, int colon) {
        if (fld.status == Status.ALIVE) {
            Point p = field.getPoint(row, colon);
            if (p.getNote() == Note.UNKNOWN) {
                p.setNote(Known);
                if (p.getState() == State.MINED) {
                    fld.status = Status.DEAD;
                    return false;
                } else if (field.getPointScore(row, colon) == 0) {
                    touchSuccessors(row, colon);
                }
            }
        }
        return true;
    }

    private void touchSuccessors(int row, int colon) {
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = colon - 1; j <= colon + 1; ++j) {
                if (i >= 0 && i < map.length &&
                    j >= 0 && j < map[0].length) {
                    if (!touch(i, j)) {
                        throw new UnexpectedBehaviorException("score == 0, but it's not");
                    }
                }
            }
        }
    }

    public void mark(int row, int colon) {
        if (fld.status == Status.ALIVE) {
            Point p = field.getPoint(row, colon);
            Note note = p.getNote();
            switch(note) {
                case Note.UNKNOWN:
                    p.setNote(Note.UNKNOWN_MINE);
                    break;
                case Note.UNKNOWN_MINE:
                    p.setNote(Note.UNKNOWN_FLAG);
                case Note.UNKNOWN_FLAG:
                    p.setNote(Note.UNKNOWN);
                    break;
                default:
                    break;
            }   
        }
    } 

}