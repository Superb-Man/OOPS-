#include<cstdlib>
#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>

using namespace std ;

class Mythread{
    thread t ;
public:
    int last ;
    int sum ;
    static int pos ;
    Mythread(){
        sum = 0 ;
        //Starting the thread ; 
        start() ;
    }
    void start(){
        t = thread(&Mythread::run,this) ;
    }
    void run(){
        last = pos+10 ;
        sum = last*(last+1) ;
        sum/=2 ;
        sum = sum - (pos*(pos+1))/2 ;
        pos = last ;
        last = pos + 10 ;
    }
    void terminate(){
        t.join() ;
    }
} ;
int Mythread:: pos = 0 ;
int main(){
    Mythread *myt = new Mythread[10] ;
    for(int i = 0 ;i < 10 ;i++) (myt+i)->terminate() ;
    int total  = 0 ;
    for(int i = 0 ; i < 10 ; i++)   total+=(myt+i)->sum ;
    cout<<total << endl;
    delete [] myt ;
}