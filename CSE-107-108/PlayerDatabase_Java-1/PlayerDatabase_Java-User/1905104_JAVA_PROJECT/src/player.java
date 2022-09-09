class player{

    private int     age ;
    private double  weeklySalary ;
    private int     jerseyNumber ;
    private double  height ;
    private String  playerName ;
    private String  playerPosition ;
    private String  clubName ;
    private String  countryName ;

    public player (){
        this.clubName       = null ;
        this.countryName    = null ;
        this.age            = 0 ;
        this.weeklySalary   = 0 ;
        this.jerseyNumber   = 0 ;
        this.height         = 0 ;
        this.playerName     = null ;
        this.playerPosition = null ;
    }

    public void setClubName( String clubName )
    {
        this.clubName = clubName ;
    }
    public String getClubName() {
        return clubName;
    }

    public void setCountryName( String countryName ){
        this.countryName = countryName ;
    }

    public String getCountryName(){
        return  countryName ;
    }

    public void setAge( int age){
        this.age = age;
    }

    public int getAge(){
        return age ;
    }

    public void setPlayerName( String playerName ){
        this.playerName = playerName ;
    }

    public String getPlayerName() {
        return playerName ;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getHeight()
    {   return height ; }

    public void setJerseyNumber(int jerseyNumber) {
        this.jerseyNumber = jerseyNumber;
    }

    public int getJerseyNumber() {
        return jerseyNumber;
    }

    public void setPlayerPosition(String playerPosition) {
        this.playerPosition = playerPosition;
    }
    public String  getPlayerPosition(){
        return  playerPosition ;
    }

    public void setWeeklySalary(double weeklySalary) {
        this.weeklySalary = weeklySalary;
    }

    public double getWeeklySalary() {
        return weeklySalary;
    }

    public void showPlayerInfo (){
        System.out.println("Players Name  : "+ getPlayerName());
        System.out.println("Country       : "+ getCountryName());
        System.out.println("Age           : "+ getAge()+ " years");
        System.out.println("Height        : "+ getHeight()+" meters");
        System.out.println("Club          : "+ getClubName());
        System.out.println("Position      : "+ getPlayerPosition());
        System.out.println("Jersey Number : "+ getJerseyNumber());
        System.out.println("Weekly Salary : "+ getWeeklySalary());
        System.out.println() ;
    }

}