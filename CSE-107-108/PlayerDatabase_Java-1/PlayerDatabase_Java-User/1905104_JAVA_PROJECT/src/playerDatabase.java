import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.concurrent.atomic.AtomicReference;

class playerDatabase {
    public static List<player> PlayersList       = new ArrayList<>() ;
    public static List<club>   ClubsList         = new ArrayList<>() ;
    public static List<country>CountriesList     = new ArrayList<>() ;
    private static final String INPUT_FILE_NAME  = "players.txt";
    private static final String OUTPUT_FILE_NAME = "players.txt";

    public static void readFile() throws Exception{
        BufferedReader br = new BufferedReader(new FileReader(INPUT_FILE_NAME));

        while(true){
            String line = br.readLine();
            if (line == null) break;
            String[] tokens = line.split(",");
            player Player   = new player() ;
            Player.setPlayerName(tokens[0]) ;
            Player.setCountryName(tokens[1]) ;
            Player.setAge(Integer.parseInt(tokens[2])) ;
            Player.setHeight(Double.parseDouble(tokens[3])) ;
            Player.setClubName(tokens[4]) ;
            Player.setPlayerPosition(tokens[5]) ;
            Player.setJerseyNumber(Integer.parseInt(tokens[6])) ;
            Player.setWeeklySalary(Double.parseDouble((tokens[7]))) ;
            PlayersList.add(Player) ;
        }

        br.close() ;
    }

    public static void loadClubs(){
        for( player Player : PlayersList){
            boolean flag = true ;
            for( club Club :ClubsList ) {
                if (Club.getClubName().toLowerCase().equals(Player.getClubName().toLowerCase())) {
                    Club.addPlayer(Player);
                    flag = false;
                    break;
                }
            }
            if( flag ){
                club c = new club() ;
                c.setClubName(Player.getClubName());
                c.addPlayer(Player) ;
                ClubsList.add( c ) ;
            }
        }
    }
    public static void loadCountries(){
        //CountriesList.clear() ;
        for( player Player : PlayersList){
            boolean flag = true ;
            for( country Country : CountriesList ){
                if(Country.getCountryName().toLowerCase().equals(Player.getCountryName().toLowerCase())){
                    Country.addPlayer(Player) ;
                    flag = false ;  break ;
                }
            }
            if( flag ){
                country c = new country() ;
                c.setCountryName(Player.getCountryName());
                c.addPlayer(Player) ;
                CountriesList.add( c ) ;
            }
        }
    }
    public static void writeFile() throws Exception{
        BufferedWriter bw = new BufferedWriter(new FileWriter(OUTPUT_FILE_NAME));
        for(player Player : PlayersList ) {
            bw.write(Player.getPlayerName() + "," + Player.getCountryName() + "," + Player.getAge() + "," + Player.getHeight() + "," + Player.getClubName() + "," + Player.getPlayerPosition() + "," + Player.getJerseyNumber() + "," + Player.getWeeklySalary());
            bw.write("\n");
        }
        bw.close() ;
    }

    public static void showPlayerInfo(){
        for(player Player : PlayersList){
            Player.showPlayerInfo() ;
        }
    }
    public static void showClubInfo(){
        for(club Club : ClubsList){
            Club.showClubInfo();
        }
    }

}
