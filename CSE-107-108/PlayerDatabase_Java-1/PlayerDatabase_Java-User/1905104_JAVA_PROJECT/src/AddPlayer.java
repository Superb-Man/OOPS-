class AddPlayer{
    private static player P = new player() ;

    public static void addPlayerTolist(){
        int optionToken = userInput.getMenu() ;
        if (optionToken == 1){
            for(player Player : playerDatabase.PlayersList ) {
                if (Player.getPlayerName().toLowerCase().equals(userInput.line.toLowerCase())) {
                    System.out.println("There is already a player with this name .");
                    System.out.println() ;
                    userInput.returnMenu();
                    userInput.returnOption();
                    P = new player();
                    return;
                }
            }
            P.setPlayerName(userInput.line.substring(0,1).toUpperCase()+userInput.line.substring(1).toLowerCase());
            userInput.updateMenu() ;
        }
        else if(optionToken == 2){
            P.setCountryName(userInput.line.substring(0,1).toUpperCase()+userInput.line.substring(1).toLowerCase()) ;
            userInput.updateMenu() ;
        }
        else if(optionToken == 3){
            try{
                int age = Integer.parseInt(userInput.line) ;
                if(age < 0)  System.out.println("Age cannot be negetive ");
                else {
                    P.setAge(age) ;
                    userInput.updateMenu() ;
                }
            }
            catch(NumberFormatException e){
                System.out.println("Invalid Age ") ;
            }
        }
        else if(optionToken == 4){
            try{
                double height = Double.parseDouble(userInput.line) ;
                if(height <= 0.0 ) System.out.println("Height cannot be negetive or zero");
                else {
                    P.setHeight(height) ;
                    userInput.updateMenu() ;
                }
            }
            catch(NumberFormatException e){
                System.out.println("Invalid Height") ;
            }
        }
        else if(optionToken == 5){
            for(club Club : playerDatabase.ClubsList){
                if(Club.getClubName().toLowerCase().equals(userInput.line.toLowerCase()) && Club.getPlayerCount() >=7 ){
                    System.out.println("The Club has already 7 players!");
                    System.out.println() ;
                    userInput.returnMenu() ;
                    userInput.returnOption() ;
                    P = new player() ;
                    return;
                }
            }
            P.setClubName(userInput.line.substring(0,1).toUpperCase()+userInput.line.substring(1)) ;
            userInput.updateMenu() ;
        }
        else if(optionToken == 6){
            String [] Position = {"Goalkeeper", "Defender", "Forward", "Midfielder"} ;
            for(String S : Position){
                if(S.toLowerCase().equals(userInput.line.toLowerCase())){
                    P.setPlayerPosition(userInput.line.substring(0,1).toUpperCase()+userInput.line.substring(1).toLowerCase()) ;
                    userInput.updateMenu() ;
                    return;
                }
            }
            System.out.println("Invalid Position");
        }
        else if(optionToken == 7){
            try{
                int number = Integer.parseInt(userInput.line) ;
                if(number < 0) System.out.println("Position cannot be negetive");
                else {
                    for(club Club : playerDatabase.ClubsList){
                        if(Club.getClubName().equalsIgnoreCase(P.getClubName())){
                            for(player Player : Club.allPlayers() ){
                                if(Player.getJerseyNumber() == number ){
                                    System.out.println("There's already a player with jersey no "+number ) ;
                                    return ;
                                }
                            }
                            P.setJerseyNumber(number) ;
                            userInput.updateMenu() ;
                            return ;
                        }
                    }
                    P.setJerseyNumber(number) ;
                    userInput.updateMenu() ;
                }
            }
            catch(NumberFormatException e){
                System.out.println("Invalid Jersey Number");            }
        }
        else if(optionToken == 8){
            try {
                double salary = Double.parseDouble(userInput.line) ;
                if(salary < 0.0){
                    System.out.println("Salary cannot be negetive") ;
                }
                else {
                    P.setWeeklySalary(salary);
                    playerDatabase.PlayersList.add(P);
                    playerDatabase.loadClubs();
                    playerDatabase.loadCountries();
                    System.out.println("Successfully added a palyer to list!");
                    System.out.println() ;
                    userInput.returnMenu();
                    userInput.returnOption();
                    P = new player();
                }

            }
            catch (NumberFormatException e){
                System.out.println("Invalid weekly salary");
            }
        }
    }
}
