package Thread.Creating_Thread;//Complete the following Java code that finds the total number of square numbers from a 100000 random integers array using an array of 20 threads in parallel. You cannot write any more classes.

import java.util.Random;
import java.lang.Math;

class ParallelSquareCounter implements Runnable {
    private int[] numbers;
    private int startIndex;
    private static final int NUMBER_COUNT =20 ;
    private int squareCount;
    // you are not allowed to add any more fields

    // you are not allowed to change this constructor, and you are not allowed to add any more constructor
    ParallelSquareCounter(int[] numbers, int startIndex) {
        this.numbers     = numbers;
        this.startIndex  = startIndex;
        this.squareCount = 0;
    }
    int getStartIndex(){
        return startIndex ;
    }
    // your code here

    public void run()
    {
        for(int i=startIndex;i<startIndex+NUMBER_COUNT;i++)
        {
            int n = numbers[i];
            double m = (double) n ;
            m = Math.sqrt(m);
            int j = (int) m ;

            if(j*j==n) {
                squareCount++;
            }
        }
    }

    public int getSquareCount()
    {
        return squareCount;
    }
}

public class Main {
    public static void main(String[] args) {
        Random random = new Random();
        final int NUMBER_COUNT = 100 ;
        final int THREAD_COUNT =  5 ;
        int[] numbers = new int[NUMBER_COUNT];
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = i+1 ;
            System.out.println(numbers[i]);
        }
        ParallelSquareCounter[] parallelSquareCounters = new ParallelSquareCounter[THREAD_COUNT];
        Thread[] threads = new Thread[THREAD_COUNT];
        // your code here

        for(int i=0;i<THREAD_COUNT;i++) {
            parallelSquareCounters[i] = new ParallelSquareCounter(numbers, i*(NUMBER_COUNT/THREAD_COUNT));
            threads[i]  = new Thread(parallelSquareCounters[i]);
            threads[i].start();
        }
        try{
            for(int i=0;i<THREAD_COUNT;i++)
                threads[i].join();
        }catch (InterruptedException e) {
            System.out.println(e);
        }

        int ans =0;

        for(int i=0;i<THREAD_COUNT;i++)
        {
            System.out.println(parallelSquareCounters[i].getStartIndex()+1 +"-----"+(i+1)*(NUMBER_COUNT/THREAD_COUNT)+" : "+parallelSquareCounters[i].getSquareCount());
            ans+= parallelSquareCounters[i].getSquareCount();
        }
        System.out.println(ans);

    }
}