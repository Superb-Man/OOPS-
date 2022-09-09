#include<iostream>
#include<stdlib.h>
#include<vector>

template <typename T>
void merge_array(T* arr,int left,int middle,int right){
    int n = middle - left + 1;
    int m = right - middle;

    T arrayA[n] ;
    T arrayB[m] ;

    //storing leftside sorted array in temp array
    for(int i = 0; i < n; i++)
        arrayA[i] = arr[left+i] ;

    //storing rightside sorted array in temp array
    for(int i = 0 ; i < m ; i++)
        arrayB[i] = arr[middle+1+i] ;

    //merging two temp arrays in a third one
    int i = 0, j= 0 , k = left;
    while(i < n && j < m)
    {
        if(arrayA[i] > arrayB[j]) arr[k++] = arrayB[j++] ;
        else arr[k++] = arrayA[i++] ;
    }

    for(; i < n ; i++)
        arr[k++] = arrayA[i];
    for(; j < m ; j++)
        arr[k++] = arrayB[j];
}
template <typename T>
void mergeSort(T* arr , int left , int right){
    int middle = (left + right)/ 2;

    if(left < right) {
        mergeSort(arr, left, middle) ;
        mergeSort(arr, middle + 1, right) ;

        merge_array(arr, left, middle, right) ;
    }
}

int main(){

    int n ; 
    std::cin >> n ;
    int* array = new int[n] ;

    for(int i=0;i<n;i++) std::cin >> array[i] ;

    mergeSort(array, 0 ,n-1) ;
    for(int i = 0 ; i< n ;i++){
        std::cout << array[i] << " " ;
    }
    
    std::cout << '\n' ;
    
    std::pair<int , int> parr[n] ;
    for(int i = 0 ; i < n ; i++){
        std::cin >> parr[i].first >> parr[i].second ;
    }
    
    mergeSort(parr,0,n-1) ;
    
    for(int i = 0 ; i < n ;i++){
        std::cout << parr[i].first << " " << parr[i].second <<std::endl;
    }
    
    std::vector<int>vec ;
    for(int i = 0 ; i < n ; i++){
        int x ;
        std::cin >> x ;
        vec.push_back(x) ;
    }
    
    mergeSort(vec.data(),0, n-1) ;
    for(int i = 0 ; i < n ; i++){
        std::cout << vec[i] << " " ;
    }
    
}