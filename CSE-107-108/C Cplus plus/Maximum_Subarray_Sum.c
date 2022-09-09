#include<stdio.h>
#include<stdlib.h>
int max(int x,int y)
{
    if(x>=y) return x;
    else return y;
}
int maxi(int x,int y,int z)
{
    return max(max(x,y),z);
}
int maxcross(int *p,int l,int m,int h)
{
    int lsum=0,rsum=0,i,rmx=INT_MIN,lmx=INT_MIN;
    for(i=m;i>=l;i--)
    {
        lsum+=*(p+i);
        lmx=max(lsum,lmx);
    }
    for(i=m+1;i<=h;i++)
    {
        rsum+=*(p+i);
        rmx=max(rmx,rsum);
    }
    return maxi(rmx,lmx,lmx+rmx);
}
int maxsum(int *p,int l,int h)
{
    if(l==h)
    {
        return *(p+l);
    }
    int m=(l+h)/2;
    return maxi(maxsum(p,l,m),maxsum(p,m+1,h),maxcross(p,l,m,h));
}
int main()
{
    int *p;
    int n;
    scanf("%d", &n);
    p=(int *) malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d", p+i);
    }
    int sum;
    sum=maxsum(p,0,n-1);
    printf("%d", sum);
    free(p);
}
