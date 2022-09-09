import java.util.Scanner;
public class Main {
    public static void main(String [] args) throws Exception {
        playerDatabase.readFile() ;
        playerDatabase.loadClubs() ;
        playerDatabase.loadCountries() ;
        System.out.println("Player Database");
        userInput.showOptionAndMenu() ;
        System.out.println("Enter a digit between 1 and 4");
        while(userInput.getTrueResult() == true){
            userInput.exucuteCommand() ;
        }
        playerDatabase.writeFile() ;
        return;
    }
}
