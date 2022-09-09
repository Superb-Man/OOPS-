package Thread.Creating_Thread;

class Thread2 extends Thread{
    Thread2(){
        super("Thread") ;
        start() ;
    }
    public void run() {
        try{
            for(int i =1 ;i< 10 ;i++){
                Thread.sleep(1000);
                System.out.println(i*i);
            }
        }catch (InterruptedException e){

        }
    }
}
public class NewThread {
    public static void main(String [] args){
        Thread2 thread = new Thread2() ;
    }
}
