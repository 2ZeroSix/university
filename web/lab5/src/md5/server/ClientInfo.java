package md5.server;

import java.util.Objects;
import java.util.UUID;


public class ClientInfo {
    private UUID uuid;
    private int startTaskIndex;
    private int finalTaskIndex;
    private Long startTime;

    ClientInfo(UUID uuid, int startTaskIndex, int finalTaskIndex){
        this.uuid           = uuid;
        this.startTaskIndex = startTaskIndex;
        this.finalTaskIndex = finalTaskIndex;
        this.startTime      = System.currentTimeMillis();
    }

    public Long getStartTime(){
        return startTime;
    }

    public int getStartTaskIndex(){
        return startTaskIndex;
    }

    public int getFinalTaskIndex(){
        return finalTaskIndex;
    }

    public UUID getUuid() {
        return uuid;
    }

    public void setUuid(UUID uuid){
        this.uuid = uuid;
    }
    public void setTime(Long time){
        this.startTime = time;
    }

    public void setStartTaskIndex(int startTaskIndex) {
        this.startTaskIndex = startTaskIndex;
    }

    public void setFinalTaskIndex(int finalTaskIndex) {
        this.finalTaskIndex = finalTaskIndex;
    }

    @Override
    public boolean equals(Object other){
        if (other == null) return false;
        if (other == this) return true;
        if (!(other instanceof ClientInfo))return false;
        ClientInfo otherMyClass = (ClientInfo)other;
        if (otherMyClass.getUuid().equals(uuid))
            return true;
        else
            return false;
    }
    @Override
    public int hashCode(){
        return Objects.hash(uuid);
    }

}
