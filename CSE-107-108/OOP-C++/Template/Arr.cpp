#include<iostream>
#include<stdlib.h>

#define MAX_SIZE 10
template<typename T>
class ArrList{

private: 
    int defaultsize ;
    int size ;
    int incr ;
    int cur ;
    T*  arr ; 

    void copy( T* a, T* b ,int _bsize) {
        for(int i = 0 ; i < _bsize ;i++) {
            a[i] = b[i] ;
        }
    }

    void update() {
        T* _arr = new int[size] ;
        copy(_arr , arr, size) ;
        
        delete [] arr ;

        defaultsize+=incr;
        arr = new int[defaultsize] ;
        
        copy(arr,_arr, size) ;

        delete [] _arr ;
    }

public:

    ArrList(int _size = MAX_SIZE) {
        cur = size = 0 ;
        defaultsize = _size ;
        arr = new T[_size] ;
        incr = defaultsize ;
    }

    ArrList(T* _arr, int _size, int _memorysize){
        size = cur = 0 ;
        defaultsize = incr = _memorysize ;
        arr = new T[defaultsize] ;
        int i = 0 ;
        while(size <_size) {
            if(size + 1 > defaultsize) update() ;
            arr[size++] = _arr[i++] ;

            //or just
            //append(_arr[i++]);
        }

    }

    ~ArrList(){
        delete []arr ;
        std :: cout <<"Memory Freed" <<'\n' ;
    }

    void clear(){
        delete [] arr ;
        cur = size = 0 ;
        defaultsize = incr = MAX_SIZE ;
        arr = new T[defaultsize] ;
    }

    /*
     * 
     * 
     */
    void insert(const T& item){
        if(size + 1 > defaultsize)  update() ;
        
        for(int i = size ; i > cur ;i--) arr[i] = arr[i-1] ; 

        arr[cur] = item ; 
        ++size ; 
    }

    /*
     * 
     * 
     */

    void append(const T& item){
        if(size + 1 > defaultsize ) update() ;
        arr[size++] = item ;
    }

    /*
     * 
     * 
     */

    T remove(){
        if(cur>=0 && cur < size){
            T ret = arr[cur] ;

            for(int i = cur ; i< size-1 ;i++) arr[i] = arr[i+1] ;
            size-- ;

            return ret ;
        }

    }

    void moveToStart() {
        cur = 0 ;
    }

    void moveToEnd(){
        cur = size-1 ;
    }

    void prev(){
        
        if(cur) cur-- ;
    }

    void next(){
        if(cur < size) cur++ ; 
    }

    int length() const{
        return size ;
    }

    int curPos(){
        return cur ;
    }

    void moveToPos(int idx){
        if(cur >=0 && cur < size) {
            cur = idx ;
            return ;
        }
    }

    T getValue() const{
        if(cur >= 0 && cur < size) return arr[cur] ;
    }
    
    int searchItem(const T& item){
        for(int i = 0 ; i < size ;i++){
            if(arr[i] == item) return i ;
        }
        return -1 ;  
        
    }

    void print(){
        //if(size == 0) std::cout <<"|" ;
        
        for(int i = 0 ;i < size ;i++){
            if(cur == i) std::cout << "|" << " " ;
            std::cout << arr[i] <<" " ;
        }
        std::cout << '\n' ;
    }


};

int main(){
    int ara[6] ;
    for(int i = 0 ; i< 6; i++){
        ara[i] = i*i+1 ;
    }
    ArrList<int>lii,li(ara,6,3) ;
    //std::cout << lii.getValue() ;
    lii.insert(765) ;
    lii.insert(76) ;
    lii.print() ;
    li.insert(77) ;
    li.print() ;
    li.moveToEnd() ;
    li.print() ;
    li.insert(9) ;
    li.print() ;
    li.print() ;
    //li.moveToStart() ;
    li.moveToEnd() ;
    li.print() ;
    li.moveToPos(4) ;
    //li.prev() ;
    /*while(li.length()!=0){
        std :: cout <<li.length() <<" " ;
        std:: cout <<li.getValue() <<"\n" ;
        li.print() ;
        li.prev() ;//li.next() ;
    }*/
    
    li.print() ;
    li.remove() ;
    li.print() ;
    std::cout << li.searchItem(288) <<'\n' ;
    li.moveToStart() ;
    li.print() ;
    li.remove() ;
    li.print() ;
    li.clear() ;
    li.clear() ;
    li.print() ;
    li.append(765) ;
    li.print() ;
}