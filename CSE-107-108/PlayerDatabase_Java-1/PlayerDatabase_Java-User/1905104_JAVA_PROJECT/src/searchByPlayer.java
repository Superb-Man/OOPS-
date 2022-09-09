import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class searchByPlayer {

     public player searchByName(String Input){
        for(player Player : playerDatabase.PlayersList){
            if(Player.getPlayerName().toLowerCase().equals(Input.toLowerCase())){
                return Player ;
            }
        }
        return null ;
    }
    public static List<player> searchByCountryAndClub(String Input1, String Input2){
         List< player > P = new ArrayList<>() ;
         if(Input2.toLowerCase().equals("any")){
             for(player Player : playerDatabase.PlayersList){
                 if(Player.getCountryName().toLowerCase().equals(Input1.toLowerCase())) {
                     P.add(Player);
                 }
             }
             return P ;
         }
         else
         {
             for(player Player : playerDatabase.PlayersList){
                 if(Player.getCountryName().toLowerCase().equals(Input1.toLowerCase()) && Player.getClubName().toLowerCase().equals(Input2.toLowerCase())) {
                     P.add(Player);
                 }
             }
             return P ;
         }
    }
    public List<player> searchByPosition(String Input){
         List< player > P = new ArrayList<>() ;
         for(player Player : playerDatabase.PlayersList){
            if(Player.getPlayerPosition().toLowerCase().equals(Input.toLowerCase())) {
                P.add(Player);
            }
        }
        return P ;
    }
    public static List<player> searchBySalary(double Input1, double Input2){
        List< player > P = new ArrayList<>() ;
        for(player Player : playerDatabase.PlayersList){
            if(Player.getWeeklySalary() >= Input1 && Player.getWeeklySalary() <= Input2) {
                P.add(Player);
            }
        }
        return P ;
    }
    public Map<String , Integer> countryWisePlayerCount(){
         Map<String, Integer> map = new HashMap<>() ;
         for(country Country : playerDatabase.CountriesList ){
             map.put(Country.getCountryName(),Country.getPlayerCount()) ;
         }
         return map ;
    }
}
