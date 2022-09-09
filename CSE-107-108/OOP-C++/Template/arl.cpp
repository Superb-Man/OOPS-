#include<iostream>
#include<stdlib.h>

#define MAX_SIZE 10
template<typename T>
class ArrList{

private: 
    int defaultsize ;
    int size ;
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

        defaultsize*= 2;
        arr = new int[defaultsize] ;
        
        copy(arr,_arr, size) ;

        delete [] _arr ;
    }

public:

    ArrList(int _size = MAX_SIZE) {
        cur = size = 0 ;
        defaultsize = _size ;
        arr = new T[_size] ;   
    }

    ArrList(T* _arr, int _size, int _memorysize){
        size = cur = 0 ;
        defaultsize = _memorysize ;
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
        defaultsize = MAX_SIZE ;
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
        std::cout << "No element at tail" <<'\n' ;
        exit(0) ;

    }

    void moveToStart() {
        cur = 0 ;
    }

    void moveToEnd(){
        cur = size ;
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
        std::cout <<"Invalid Position" <<'\n' ;
        exit(0) ;
    }

    T getValue() const{
        if(cur >= 0 && cur < size) return arr[cur] ;
        std::cout <<"No elements in the list'\n" ;
        exit(0) ;
    }
    
    int searchItem(const T& item){
        for(int i = 0 ; i < size ;i++){
            if(arr[i] == item) return i ;
        }
        return -1 ;  
        
    }

    void print(){
        if(size == 0) std::cout <<"|" ;
        
        for(int i = 0 ;i < size ;i++){
            if(cur == i) std::cout << "|" << " " ;
            std::cout << arr[i] <<" " ;
        }
        if(cur == size && cur != 0) std::cout <<"|" ;  
        std::cout << '\n' ;
    }


};