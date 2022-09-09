#include<iostream>
#include<cstring>

template<typename T> 
bool find(const T& object , T* arr , const int size){
    for(int i = 0 ; i < size ;i++){
        if(arr[i] == object){
            return true ;
        }
    }

    return false ;
}

int main(){
    int a[] ={1,2,3,4} ;
    char* c = "I am Toriqe" ;
    if(find(1,a,4)==true) std::cout <<"true" <<'\n' ;
    else std::cout << "false" <<'\n' ;

    if(find('c',c,(int)strlen(c))==true) std::cout <<"true" <<'\n' ;
    else std::cout << "false" <<'\n' ;
}