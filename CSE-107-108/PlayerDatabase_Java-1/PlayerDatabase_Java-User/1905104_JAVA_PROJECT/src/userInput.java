import java.util.List;
import java.util.Map;
import  java.util.Scanner ;
class userInput {
    public static Scanner scan           = new Scanner(System.in) ;
    private static int option            = 0 ;
    private static int [] menu           = { 0,0,0,0 } ;
    private static int countCountryInput = 0 ;
    private static int salaryLowebound   = 0 ;
    public static String line            = null ;
    private static String str1           = null ;
    private static double low            = 0 ;
    private static boolean var           = true ;
    public static boolean getTrueResult(){
        return var ;
    }
    public static int getOption() {
        return option;
    }
    public static int getMenu(){
        return menu[option - 1] ;
    }
    public static void updateMenu(){
        menu[ option -1] = menu [ option -1 ] + 1 ;
    }
    public static void returnOption(){
        option = 0 ;
    }
    public static void returnMenu(){
        menu [ option - 1 ] = 0 ;
    }
    public static void showOptionAndMenu(){
        if(option == 0){
            System.out.println("(1) Search Players ");
            System.out.println("(2) Search Clubs ");
            System.out.println("(3) Add Player ");
            System.out.println("(4) Exit System ");
        }

        if( option == 1){
            if ( menu[option - 1] == 0){
                System.out.println("Player Searching Options :") ;
                System.out.println("(1) By Player Name") ;
                System.out.println("(2) By Club and Country") ;
                System.out.println("(3) By Position") ;
                System.out.println("(4) By Salary Range") ;
                System.out.println("(5) Country-wise player count") ;
                System.out.println("(6) Back to Main Menu") ;
            }
            else if(menu[option - 1] == 1){
                System.out.print("Enter Player Name : ") ;
            }
            else if(menu[option - 1] == 2){
                if(countCountryInput == 0 ){
                    System.out.print("Country : ") ;
                }
                else if( countCountryInput == 1){
                    System.out.print("Club : ");
                }
            }
            else if(menu[option - 1] == 3){
                System.out.print("Position : ");
            }
            else if(menu[option - 1] == 4){
                if(salaryLowebound == 0){
                    System.out.print("Lower Range : ");
                }
                else {
                    System.out.print("Upper Range : ");
                }
            }
        }

        if(option == 2){
            if(menu[ option - 1] == 0){
                System.out.println("Club Searching Options:") ;
                System.out.println("(1) Player(s) with the maximum salary of a club") ;
                System.out.println("(2) Player(s) with the maximum age of a club") ;
                System.out.println("(3) Player(s) with the maximum height of a club") ;
                System.out.println("(4) Total yearly salary of a club") ;
                System.out.println("(5) Back to Main Menu" ) ;
            }
            else {
                System.out.print("Club : ");
            }
        }

        if(option ==3 ){
            if(menu[option -1] == 1)    System.out.print("Name           : ") ;
            else if(menu[option-1]==2) System.out.print("Country        : ") ;
            else if(menu[option-1]==3) System.out.print("Age            : ") ;
            else if(menu[option-1]==4) System.out.print("Height         : ") ;
            else if(menu[option-1]==5) System.out.print("Club           : ") ;
            else if(menu[option-1]==6) System.out.print("Position       : ") ;
            else if(menu[option-1]==7) System.out.print("JerseyNumber   : ") ;
            else if(menu[option-1]==8) System.out.print("Weekly Salary  : ") ;
        }
    }
    public static void  setOptionAndMenu(){
        if(option ==0 ){
            try{
                option = Integer.parseInt( line ) ;
                if(option >4 || option < 1){
                    option = 0 ;
                    System.out.println("Enter a digit between 1 and 4 ") ;
                }
            }
            catch (NumberFormatException e){
                System.out.println("Enter a digit between 1 and 4 ") ;
            }
        }

        else if(option == 1){
            if(menu[ option-1 ] == 0) {
                try {
                    menu[option - 1] = Integer.parseInt(line);
                    if (menu[option - 1] < 1 || menu[option - 1] > 6) {
                        menu [option - 1] = 0 ;
                        System.out.println("Enter a digit between 1 and 6 ");
                    }
                    else if (menu[option - 1] == 6) {
                        menu[option - 1] = 0;
                        option = 0;
                    }
                    else if(menu[option -1 ]== 5 ){
                        searchByPlayer CountryCountSearch = new searchByPlayer() ;
                        Map<String,Integer> map = CountryCountSearch.countryWisePlayerCount() ;
                        for(country Country : playerDatabase.CountriesList){
                            System.out.println(Country.getCountryName() + " has "+ map.get(Country.getCountryName())+ " players") ;
                            System.out.println() ;
                            menu[option -1] = 0 ;
                        }
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Enter a digit between 1 and 6 ");
                }
            }
            else if(menu [option - 1] == 1){
                searchByPlayer PlayerName = new searchByPlayer() ;
                if(PlayerName.searchByName( line ) == null ){
                    System.out.println("There is no player with that name");
                    System.out.println() ;
                }
                else
                {
                    PlayerName.searchByName(line).showPlayerInfo() ;
                    System.out.println() ;
                }
                menu[option - 1] = 0;
            }
            else if(menu[option - 1] == 2){
                if(countCountryInput == 0) {
                    str1 = line ; countCountryInput = 1 ;
                }
                else if(countCountryInput == 1){
                    String str2 = line ; countCountryInput = 0;
                    if(searchByPlayer.searchByCountryAndClub( str1 ,str2).isEmpty() == true ){
                        System.out.println("No such player with this country and club");
                        System.out.println();
                        str1 = null ;
                    }
                    else
                    {
                        List<player> Plist = searchByPlayer.searchByCountryAndClub(str1,str2) ;
                        for(player Player : Plist){
                            Player.showPlayerInfo() ;
                            System.out.println() ;
                        }
                        str1 = null ;
                    }
                    menu[option - 1] = 0;
                }
            }
            else if (menu[option - 1] == 3){
                try{
                    searchByPlayer PositionSearch = new searchByPlayer() ;
                    if(PositionSearch.searchByPosition(line).isEmpty() == true){
                        System.out.println("No such player with this position") ;
                        System.out.println() ;
                    }
                    else {
                        List<player> Plist = PositionSearch.searchByPosition(line) ;
                        for(player Player : Plist){
                            Player.showPlayerInfo() ;
                            System.out.println() ;
                        }
                    }
                    menu[option - 1] = 0;
                    //showOptionAndMenu() ;
                }
                catch(NumberFormatException e){
                    System.out.println("Invalid position ") ;
                }
            }
            else if(menu[option - 1] ==4){
                try{
                    if(salaryLowebound ==0 ){
                        low = Double.parseDouble(line) ;
                        if(low>0.0){
                            salaryLowebound = 1 ;
                        }
                        else {
                            System.out.println("Please enter a non-negetive number ") ;
                        }
                    }
                    else if(salaryLowebound == 1){
                        double high = Double.parseDouble(line) ;
                        if(low>high){
                            System.out.println("Please enter a larger number than lower range ") ;
                        }
                        else{
                            if(searchByPlayer.searchBySalary(low,high).isEmpty() == true ){
                                System.out.println("No such player with this weekly salary range");
                                System.out.println();
                                salaryLowebound = 0 ;
                            }
                            else {
                                List<player> Plist = searchByPlayer.searchBySalary(low,high) ;
                                for(player Player : Plist){
                                    Player.showPlayerInfo() ;
                                    System.out.println() ;
                                }
                                salaryLowebound = 0 ;
                            }
                            menu[option - 1] = 0;
                        }
                    }
                }
                catch (NumberFormatException e){
                    System.out.println("Invalid ,salary must be double ");
                }
            }
            else if(menu [option - 1] == 6){
                menu[option - 1] = 0;
                option = 0;
            }
        }

        else if(option == 2 ){
            if(menu [option -1]==0) {
                try {
                    menu[option - 1] = Integer.parseInt(line);
                    if (menu[option - 1] < 1 || menu[option - 1] > 5) {
                        menu[option - 1] = 0;
                        System.out.println("Enter a digit between 1 and 5 ");
                        System.out.println() ;
                    }
                    else if (menu[option - 1] == 5) {
                        menu[option - 1] = 0;
                        option = 0;
                    }
                }
                catch (NumberFormatException e) {
                    System.out.println("Enter a digit between 1 and 5 ");
                    System.out.println() ;
                }
            }
            else if(menu [option - 1] == 1){
                searchByClub SalarySearch = new searchByClub() ;
                List<player> Plist = SalarySearch.maxSalaryPlayers(line) ;
                if(Plist.isEmpty() == false) {
                    for (player Player : Plist) {
                        Player.showPlayerInfo();
                    }
                    System.out.println();
                }
                else{
                    System.out.println("No such club with that name");
                    System.out.println();
                }
                menu[option - 1] = 0;
            }
            else if(menu [option - 1] == 2){
                searchByClub AgeSearch = new searchByClub() ;
                List<player> Plist = AgeSearch.maxAgePlayers(line) ;
                if(Plist.isEmpty() == false) {
                    for (player Player : Plist) {
                        Player.showPlayerInfo();
                    }
                    System.out.println();
                }
                else{
                    System.out.println("No such ck=lub with that name");
                    System.out.println();
                }
                menu[option - 1] = 0;
            }
            else if(menu [option - 1] == 3){
                searchByClub HeightSearch = new searchByClub() ;
                List<player> Plist = HeightSearch.maxHeightPlayers(line) ;
                if(Plist.isEmpty() == false) {
                    for (player Player : Plist) {
                        Player.showPlayerInfo();
                    }
                    System.out.println();
                }
                else{
                    System.out.println("No such club with that name");
                    System.out.println();
                }
                menu[option - 1] = 0;
                //showOptionAndMenu();
            }
            else if(menu [option - 1] == 4){
                searchByClub YearlySalary = new searchByClub() ;
                double tot = YearlySalary.ClubCost(line) ;
                if(tot <= 0.0){
                    System.out.println("No such club with that name");
                    System.out.println();
                }
                else{
                    System.out.print("Total salary of the Club is ") ;
                    System.out.printf("%.6f", YearlySalary.ClubCost(line)) ;
                    System.out.println() ;
                }
                menu[option - 1] = 0;
            }
            else if(menu[option - 1] == 5){
                menu [option -1] = 0 ;
                option = 0 ;
            }
        }

        if(option == 3){
            if(menu[option - 1]== 0 ) {
                menu[option - 1] = 1 ;
            }
        }
    }
    public static void  exucuteCommand(){
        line = scan.nextLine() ;
        if(option == 3){
            AddPlayer.addPlayerTolist() ;
        }
        //scan.nextLine() ;
        setOptionAndMenu() ;
        showOptionAndMenu() ;
        if(option ==4 ){
            var = false ;
        }
    }
}
