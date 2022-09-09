package Assignment;

public class League {
    private Match[] matches;
    private int matchCount;
    private int clubCount;
    private Club[] clubs;
    private String name;
    // add your variables here, if required

    public League() {
        // assume a league can have at most 5 clubs, add code for initialization accordingly
        clubs =new Club[5];
        clubCount = 0;
        matchCount = 0;
        this.name = " ";
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void printLeagueInfo(){
        System.out.println("League : " + name);
        printClubs();
    }

    public void printClubs(){
        System.out.println("Clubs:");
        // print the name of the clubs of this league, each one on a line
        for(int i=0;i<clubCount;i++)
        {
            System.out.println(clubs[i].getName());
        }
    }
    public void addClub( Club c )
    {
        clubs[clubCount] = new Club();
        clubs[clubCount].setName(c.getName());
        clubs[clubCount].setId(clubCount);
        clubs[clubCount].update((-1)*c.getPoint());
        clubCount++;
    }

    public void scheduleMatches(){
        for(int i=0;i<clubCount;i++)
        {
            clubs[i].update(clubs[i].getPoint()*(-1));
        }
        matchCount = (clubCount*(clubCount-1));
        matches = new Match[matchCount];
        int matchNo = 0;
        for (int i=0; i<clubCount; i++){
            for (int j=0; j<clubCount; j++){
                // check the constructor of the Match class and add your code here
                if(j!=i)
                {
                    matches[matchNo] = new Match(matchNo, clubs[i], clubs[j]);
                    matchNo++;
                }
                // note that there will be two matches between club A and club B
                // in the first match, club A will play as the home team and in the second match, as the away team
            }
        }
    }

    public void simulateMatches(){
        for (int i=0; i<matchCount; i++){
            matches[i].play();
        }
    }
    public void printMatches()
    {
        System.out.println("Matches: ");
        for(int i=0; i<matchCount; i++)
        {
            matches[i].showResult();
        }
    }
    public void showStandings(){
        // sort the clubs in descending order of points
        // note that, the sequence in which clubs were added to the league, should be unchanged
        // check the given sample output for clarification
        // (carefully observe the output of showStandings() followed by printLeagueInfo() method calls
        // you can use additional arrays if needed
        Club [] temp =new Club[clubCount];
        for(int i=0;i<clubCount;i++)
        {
            temp[i] = new Club();
            temp[i] = clubs[i];
        }
        for(int i=0;i<clubCount-1;i++)
        {
            for(int j=i;j<clubCount;j++)
            {
                if(temp[j].getPoint()>temp[i].getPoint())
                {
                    Club tem = temp[i];
                    temp[i] = temp[j];
                    temp[j] = tem;
                }
            }
        }
        System.out.println("Sl. - Club - Points");
        for(int i=0; i<clubCount;i++)
        {
            System.out.println(i+1+". "+temp[i].getName()+" "+temp[i].getPoint());
        }
        // print the clubs in descending order of points
    }
    // add your methods here, if required
    public void removeClub(Club c)
    {
        int idx = c.getId();
        idx--;
        for(int i=idx;i<clubCount-1;i++)
        {
            clubs[i]=clubs[i+1];
        }
        clubCount--;
    }
}
