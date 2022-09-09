import java.util.ArrayList;
import java.util.List;

class club{

    private String clubName ;
    private List<player> Players ;

    public club () {
        Players = new ArrayList<>();
    }

    public void setClubName( String clubName ){
        this.clubName = clubName ;
    }

    public String getClubName(){
        return clubName ;
    }

    public void addPlayer( player Player)
    {
        Players.add(Player) ;
    }

    public void showClubInfo(){
        for(player Player : Players){
            Player.showPlayerInfo() ;
        }
    }
    public int getPlayerCount(){
        return Players.size() ;
    }
    public List<player> allPlayers(){
        List<player> P = new ArrayList<>() ;
        for(player Player : Players){
            P.add( Player ) ;
        }

        return  P ;
    }

}