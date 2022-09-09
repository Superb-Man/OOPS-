package Assignment;

class Club {
    private int id;
    private String name;
    private int point;
    // add your code here

	// you are not allowed to write any other constructor
    public Club()
    {
        this.point=0;
        this.id = 0;
        this.name = " ";
    }
    public void setId(int id)
    {
        this.id = id;
    }
    public int getId()
    {
        return id;
    }
    public void setName(String name)
    {
        this.name=name;
    }
    public String getName() {
        return name;
    }
    public int getPoint()
    {
        return point;
    }
    public void update(int a)
    {
        point+=a;
    }

}