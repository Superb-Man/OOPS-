/*
*You are given three positive (greater than zero) integers c, d and x.

*You have to find the number of pairs of positive integers (a,b) such that equality c⋅lcm(a,b)−d⋅gcd(a,b)=x holds. Where lcm(a,b) is the least common multiple of a and b and gcd(a,b) is the greatest common divisor of a and b.

*Input
*The first line contains one integer t (1≤t≤10^4) — the number of test cases.

*Each test case consists of one line containing three integer c, d and x (1≤c,d,x≤10^7).
*/


/*
*Solution :
    c.lcm(a,b) - d.gcd(a,b) = x ;
    let , gcd(a,b) = p ;
    then , p.lcm(a,b) = ab ;
    lcm(a,b) = p.a1.b1 ;
    So,
    c.p.a1.b1 - d.p = x ;
    p(c.a1.b1 - d) = x ;

    Clearly p is a divisor of x ;
    Now precount the prime factors of numbers using the idea of seive ;

    loop(from p=1 to p*p <= x) store the divisors ;
    Now for every divisor p if c | (x/p + d) update the total ans adding 2^primecount((x/p + d)/c) ;
*/ 

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MAX_SIZE = 2e5+5 ;
ll prime[20000009];

void primecount() {
    for (ll p = 2; p<20000009; p++) {
            if (prime[p] == 0) {
            for (ll i = p; i < 20000009; i+=p)
                prime[i]++;
        }
    }
}

ll power(ll n, ll x){
    if(x == 0) return 1 ;
    else return (n * power(n,x-1));
}
 
ll logg( ll n, ll x){
    //n^pow = x;
    ll pow = 0 ;
 
    while(n<=x){
        n*= n ; ++pow ;
    }
 
    return pow ;
}

int main()
{
    ll t;
    primecount() ;
    cin >> t;
    while(t--)
    {
        ll c,d,x,i,ans1=0,j;
        vector< ll >v;
        cin >> c >> d >> x;
                for( i = 1; i*i <= x; i++)
                {
                    if(x%i == 0)
                    {
                        if(x/i == i) v.push_back(i);
                        else
                        {
                            v.push_back(i);
                            v.push_back(x/i);
                        }

                    }
                }
            for(i=0; i< v.size(); i++)
            {
                    ll z=x/v[i];
                    z+=d;
                    if(z%c) continue;
                    z/=c;
                    ans1+=power(2,prime[z]);
            }
            cout << ans1 << endl;
    }
}