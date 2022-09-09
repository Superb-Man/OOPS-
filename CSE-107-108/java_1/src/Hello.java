class Rect{
    private int h,w;
    Rect(int h,int w)
    {
        this.h=h;this.w=w;
    }
    public int area(){
        return h*w;
    }
}
public class Hello {
    public static void main(String[] args) {
        System.out.println(args.length);
        for(int i=0; i< args.length;i++)
        {
            System.out.println(args[i]);
        }
        int x = 5, y = 3;
        x = x + y - (y = x);
        System.out.print(x + " " + y + "\n");
        Rect r = new Rect(10, 5);
        //r.w=1000;
        System.out.println(r.area());
        array[][] A = new array[10][];
        String[] s = new String[10];
        for (int i = 0; i < 10; i++) {
            A[i] = new array[i + 5];
            for (int j = 0; j < i + 5; j++) {
                A[i][j] = new array(i * j);
                // System.out.print(A[i][j].get()+" ");
            }
            //System.out.println();
        }
        for (array[] X : A) {
            for (array Y : X) {
                //Y.set(1);
                System.out.print(Y.get() + " ");
            }
            System.out.println();
        }
    }
}
class array{
    private int x;
    private int size;
    private int [] ara;
    array(int x)
    {
        this.x = x;
    }

    public void set(int x)
    {
        this.x=x;
    }
    public int get()
    {
        return x;
    }
}