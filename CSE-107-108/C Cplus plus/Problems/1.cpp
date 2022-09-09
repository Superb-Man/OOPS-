/*
*You are given two integers a and b. In one turn, you can do one of the following operations:

*Take an integer c (c>1 and a should be divisible by c) and replace a with ac;
*Take an integer c (c>1 and b should be divisible by c) and replace b with bc.
*Your goal is to make a equal to b using exactly k turns.

*For the given numbers a and b, determine whether it is possible to make them equal using exactly k turns.

*Input
*The first line contains one integer t (1≤t≤10^4). Then t test cases follow.

*Each test case is contains three integers a, b and k (1≤a,b,k≤10^9).
*/

#include<bits/stdc++.h>
typedef long long int ll ;
typedef unsigned long long int ull ;
const ll mod = 1e9+7 ;
const ll MAX_SIZE = 2e5+5;

ll primecount(ll n)
{
    ll ans=0;
    while(n%2==0 && n>0){
        n/=2 ;
        ans++ ;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
                ans++;
            }
        }
    }
    if(n>1) ans++;
    return ans;
}

int main() {
    ll t = 1;
    std::cin >> t;
    while(t--)
    {
        ll a,i,j,b,k,x,y;
        std::cin >> a >> b>> k ;
        x = primecount(a) ;
        y = primecount(b) ;
        if(x+y < k) std::cout <<"NO" << std::endl;
        else
        {
            if(a == b)
            {
                if(a==1) std::cout <<"NO"<< std::endl;
                else if(k == 1) std::cout <<"NO" << std::endl;
                else std::cout <<"YES"<< std::endl;
            }
            else{
                if(k==1)
                {
                    if(a%b == 0|| b%a ==0) std::cout <<"YES"<< std::endl;
                    else std::cout <<"NO"<< std::endl;
                }
                else std::cout <<"YES"<< std::endl;
            }
        }

    }
}