int dett(int ara[][N],int x)
{
    int det=0,c,s=1,submatrix[5][5],i,j,mm,nn;
    if(x==1) return ara[0][0];
    else
    {
        for(c=0;c<x;c++)
        {
            nn=0,mm=0;
            for(i=0;i<x;i++)
            {
                for(j=0;j<x;j++)
                {
                    if(i!=0&&j!=c)
                    {
                        submatrix[nn][mm++]=ara[i][j];
                        if(mm==x-1)
                        {
                            mm=0;
                            nn++;
                        }
                    }
                }
            }
            det=det+s*(ara[0][c]*dett(submatrix,x-1));
            s=-s;
        }
    }
    return det;
}
