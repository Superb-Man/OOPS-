#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll i,n,j,k,len,cost,y=0;
    ll dp[101][101],dimen[101],s[101][101];
    cin>>n;
    for(i=0;i<n;i++) scanf("%lld", &dimen[i]);
    for(i=1;i<=n;i++) dp[i][i]=0;
    for (len=2;len<=n;len++){
        for (i=1;i<=n-len+1;i++) {
            j=i+len-1;
            dp[i][j]=INT_MAX;
            for(k=i;j<n&&k<=j-1;k++) {
                cost=dp[i][k]+dp[k+1][j]+(dimen[i-1]*dimen[k]*dimen[j]);
                if(cost<dp[i][j]){
                    dp[i][j]=cost;
                    s[i][j]=k;
                    y++;
                }
            }
        }
    }
    cout<<dp[1][n-1]<<endl;
}
