package sapper;

import static Field.*;


public class Controller {
    private Field field;
    public enum Status {ALIVE, DEAD}
    Status status;

    private void init(Field fld) {
        field = fld;
        status = Status.ALIVE;
    }
    public Controller(Field fld) {
        init(fld);
    }
    public Controller() {
        init(new Field());
    }

    public boolean touch(int row, int colon) {
        if (status == Status.ALIVE) {
            Point p = field.getPoint(row, colon);
            if (p.getNote() == Note.UNKNOWN) {
                p.setNote(Known);
                if (p.getState() == State.MINED) {
                    status = Status.DEAD;
                    return false;
                }
            }
        }
        return true;
    }

    public void lookAt(int row, int colon) {
        if (status == Status.ALIVE) {
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