enum GOT{
    Jon_Snow("Alive",7),Targaryen("Alive",7),Ned_Stark("Dead",1),Joffrey_Baratheon("Dead",4),Lannister("Alive",7) ;

    private String status ;
    private int    season ;

    GOT(String status, int season){
        setStatus(status) ;
        setSeason(season) ;
    }

    public void setStatus(String status) {
        this.status = status;
    }
    public void setSeason(int season){
        this.season = season ;
    }
    public String getStatus(){
        return status ;
    }
    public int getSeason(){
        return season ;
    }
}

public class Enum {
    public static void main(String [] args){
        GOT mini = GOT.Jon_Snow;
        for(GOT g : GOT.values()){
            if(mini.getSeason() >= g.getSeason()){
                mini = g ;
            }
        }

        System.out.println(mini);
    }
}
