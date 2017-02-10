package sapper;

import static sapper.Field.*;


public class Game {
    private Field field;

    private void init(Field fld) {
        field = fld;
    }
    public Game(Field fld) {
        init(fld);
    }
    public Game() {
        init(new Field());
    }

    public boolean touch(int row, int colon) {
        if (field.status == Status.ALIVE) {
            Field.Point p = field.getPoint(row, colon);
            if (p.getNote() == Note.UNKNOWN) {
                p.setNote(Note.KNOWN);
                if (p.getState() == State.MINED) {
                    field.status = Status.DEAD;
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
                if (!touch(i, j)) {
                    throw new UnexpectedBehaviorException("score == 0, but it's not");
                }
            }
        }
    }

    public void mark(int row, int colon) {
        if (field.status == Status.ALIVE) {
            Field.Point p = field.getPoint(row, colon);
            Note note = p.getNote();
            switch(note) {
                case UNKNOWN:
                    p.setNote(Note.UNKNOWN_MINE);
                    break;
                case UNKNOWN_MINE:
                    p.setNote(Note.UNKNOWN_FLAG);
                    break;
                case UNKNOWN_FLAG:
                    p.setNote(Note.UNKNOWN);
                    break;
                default:
                    break;
            }   
        }
    } 

}