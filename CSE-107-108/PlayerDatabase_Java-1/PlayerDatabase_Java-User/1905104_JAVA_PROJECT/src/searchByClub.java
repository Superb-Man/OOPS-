import java.util.ArrayList;
import java.util.List;

class searchByClub {
    public List<player> maxSalaryPlayers(String Input){
        List< player > P = new ArrayList<>() ;
        for(club Club : playerDatabase.ClubsList){
            if(Club.getClubName().toLowerCase().equals(Input.toLowerCase())){
                double max = 0.0 ;
                for(player PLayer : Club.allPlayers()){
                    if(max < PLayer.getWeeklySalary()){
                        max = PLayer.getWeeklySalary() ;
                    }
                }
                for(player Player : Club.allPlayers()){
                    if( max == Player.getWeeklySalary()){
                        P.add( Player ) ;
                    }
                }

                return P ;
            }
        }
        return P ;
    }

    public List<player> maxAgePlayers(String Input){
        List< player > P = new ArrayList<>() ;
        for(club Club : playerDatabase.ClubsList){
            if(Club.getClubName().toLowerCase().equals(Input.toLowerCase())){
                int max = 0 ;
                for(player PLayer : Club.allPlayers()){
                    if(max < PLayer.getAge()){
                        max = PLayer.getAge() ;
                    }
                }
                for(player Player : Club.allPlayers()){
                    if( max == Player.getAge()){
                        P.add( Player ) ;
                    }
                }

                return  P ;
            }
        }
        return P ;
    }
    public List<player> maxHeightPlayers(String Input){
        List< player > P = new ArrayList<>() ;
        for(club Club : playerDatabase.ClubsList){
            if(Club.getClubName().toLowerCase().equals(Input.toLowerCase())){
                double max = 0.0 ;
                for(player PLayer : Club.allPlayers()){
                    if(max < PLayer.getHeight()){
                        max = PLayer.getHeight() ;
                    }
                }
                for(player Player : Club.allPlayers()){
                    if( max == Player.getHeight()){
                        P.add( Player ) ;
                    }
                }
                return  P ;
            }
        }
        return P ;
    }
    public double ClubCost(String Input){
        double total = 0.0 ;
        for(club Club : playerDatabase.ClubsList){
            if(Club.getClubName().toLowerCase().equals(Input.toLowerCase())){
                for(player Player : Club.allPlayers()){
                    total = total + Player.getWeeklySalary() ;
                }
                total = total * (52.0) ;
                return total ;
            }
        }
        return 0.0 ;
    }
}
