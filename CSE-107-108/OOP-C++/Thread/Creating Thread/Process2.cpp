#include<cstdlib>
#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>

using namespace std ;
int pos ,sum[10],last,cnt;
void run(){
    last = pos+10 ;
    sum[cnt] = last*(last+1) ;
    sum[cnt]/=2 ;
    sum[cnt] = sum[cnt] - (pos*(pos+1))/2 ;
    pos = last ;
    last = pos + 10 ;
    cnt++ ;
}
int main(){
    thread *myt = new thread[10] ;
    for(int i = 0 ;i < 10 ;i++) myt[i] = thread(run) ;
    for(int i = 0  ; i < 10 ;i++) (myt+i)->join() ;
    int total  = 0 ;
    for(int i = 0 ; i < 10 ; i++)   total+=sum[i] ;
    cout<<total << endl;
    
    delete []myt ;
    
}