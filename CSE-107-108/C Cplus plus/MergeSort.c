#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int larger(int a,int b){
    return a>b;
}
int smaller(int a,int b){
    return a<=b;
}

void merge_array(int* arr,int left,int middle,int right ,int (*compare[])(int,int)){
    int n = middle - left + 1;
    int m = right - middle;

    int arrayA [n] ;
    int arrayB [m] ;

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
        if((compare[1])(arrayA[i] , arrayB [j])) arr[k++] = arrayB[j++] ;
        else arr[k++] = arrayA[i++] ;
    }

    for(; i < n ; i++)
        arr[k++] = arrayA[i];
    for(; j < m ; j++)
        arr[k++] = arrayB[j];
}

void mergeSort(int *arr , int left , int right,int (*compare[])(int,int)){
    int middle = (left + right)/ 2;

    if(left < right) {
        mergeSort(arr, left, middle,compare) ;
        mergeSort(arr, middle + 1, right,compare) ;

        merge_array(arr, left, middle, right,compare) ;
    }
}

int main(){

    int n ; scanf("%d", &n) ;
    int* array=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) scanf("%d", array+i);
    int (*compare[])(int ,int)={smaller,larger} ;

    mergeSort(array, 0 ,n-1, compare) ;
    for(int i = 0 ; i< n ;i++){
        printf("%d ", *(array+i)) ;
    }
    //For the reverse order put comapre[0] ;
}