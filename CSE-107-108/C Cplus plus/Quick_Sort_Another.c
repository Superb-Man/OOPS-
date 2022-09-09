#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(int *arr,int p,int q)
{
    int temp=*(arr+q);
    *(arr+q)=*(arr+p);
    *(arr+p)=temp;
}
int larger(int a,int b)
{
    return a>b;
}
int smaller(int a,int b)
{
    return a<=b;
}
int partition(int *arr,int left,int high,int (*compare[])(int, int))
{
    int pivot=arr[left];
    int i=left,j=high;
    while(i<j)
    {
        while((compare[0])(arr[i],pivot)==1)//arr[i]<=pivot
        {
            i++;
        }
        while((compare[1])(arr[j],pivot)==1)//arr[j]>pivot
        {
            j--;
        }
        if(i<j)
        swap(arr,i,j);
    }
    swap(arr,left,j);
    return j;
}
void q_sort(int *arr,int left,int high,int (*compare[])(int,int))
{
    if(left<high){
        int j=partition(arr,left,high,compare);
        q_sort(arr,left,j-1,compare);
        q_sort(arr,j+1,high,compare);
    }
}
int main()
{
    int n,i;
    scanf("%d", &n);
    int *arr;
    arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++) scanf("%d", arr+i);
    int (*compare[])(int ,int)={smaller,larger};
    q_sort(arr,0,n-1,compare);
    for(i=0;i<n;i++) printf("%d  ",*(arr+i));
    return 0;
}
