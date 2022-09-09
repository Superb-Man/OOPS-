package Thread.Creating_Thread;

class Thread3 implements Runnable{
    private Thread thread ;
    Thread3(){
        thread = new Thread(this) ;
        thread.start() ;
    }

    @Override
    public void run() {
        try{
            for(int i =1 ;i< 10 ;i++){
                Thread.sleep(1000);
                System.out.println(i*i);
            }
        }catch (InterruptedException e){

        }
    }
    public Thread getThread(){
        return thread ;
    }
}

public class NewThread2 {
    public static void main(String []args){
        Thread3 thread3 = new Thread3() ;
    }
}
