#include <iostream>
#include <stdlib.h>

using namespace std;

class Random
{
private:
    int** Arr;
public:
    int r,c,mini,maxi;
    Random(int x,int y,int xx,int yy)
    {
        r=x,c=y,mini=xx,maxi=yy;
        Arr=(int**) malloc(r*sizeof(int*));
        for(int i=0;i<r;i++)
        {
            Arr[i]=(int*) malloc(c*sizeof(int));
        }
    }
    void print()
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++) cout<<Arr[i][j]<<" ";
            cout<<'\n';
        }
    }
    void randomize()
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                Arr[i][j]=(rand()%(maxi+1-mini))+mini;
            }
        }
    }
    int get(int x,int y)
    {
        return Arr[x][y];
    }
    void add(int x)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                Arr[i][j]+=x;
            }
        }
    }
    int add()
    {
        int sum=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                sum+=Arr[i][j];
            }
        }
        return sum;
    }
    ~Random()
    {
        for(int i=0;i<r;i++)
        {
            free(Arr[i]);
        }
        free(Arr);
    }
};
int main()
{
     cout<<"Hello World"<<'\n';
     Random m(3,3,100,200);
     m.randomize();
     m.print();
     cout<<m.get(0,0)<<'\n';
     m.add(100);
     m.print();
     cout<<m.add()<<'\n';

     return 0;
}
