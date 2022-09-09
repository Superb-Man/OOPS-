#include<stdio.h>
typedef long long int ll;

ll phi(ll n)
{
    double result=n;
    for (ll p=2;p*p<=n;++p){
        if (n%p==0){
                while(n%p==0)       n/=p;
                result*=(1.0-(1.0/(double)p));
        }
    }
    if(n>1)
        result*=(1.0-(1.0/(double)n));
    return (ll)result;
}
int isprime(ll n)
{
    ll i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)    return 0;
    }
    return 1;
}
ll count_divisors(ll n)
{
   ll ans1=1,ans=0;
   while(n%2==0)
   {
       n/=2; ans++;
   }
   ans++;      ans1*=ans;
   for(ll i=3;i*i<=n;i+=2)
   {
       ans=0;
       if(n%i==0)
       {
           while(n%i==0)
           {
               n/=i;   ans++;
           }
       }
       ans++;   ans1*=ans;
   }
   if(n>1) ans1*=2;

   return ans1;
}
#define MAX 10000010
int prime[MAX],primes[5601500];
int tot=1;
ll mod=4294967296 ; //2^32
void sieve()
{

    for (int p = 2; p*p<10000009; p++) {
            if (prime[p]==0) {
            for (int i = p*p;i<10000009;i+=p)   prime[i]++;
        }
    }
    for(int p=2;p<=MAX-1;p++)
    {
        if(!prime[p]) primes[tot++]=p;
    }
}
ll solve(int n)
{
    ll lcm=1;
    for(int i=1;i<tot&&primes[i]<=n;i++)
    {
        int p=primes[i]%mod;
        while((ll)p*primes[i]<=n)    p=(p*primes[i])%mod;
        //p=(ll) p;
        lcm=((lcm%mod)*(p%mod))%mod;
        lcm=(lcm)%mod;
    }

    return lcm;
}
int main()
{
    sieve();
    ll t=1;
    scanf("%lld",&t) ;
    //cout<<tot<<endl<<primes[tot-1]<<endl;
   // for(int i=1;i<20;i++) cout<<primes[i]<<endl;
    for(ll cas=1;cas<=t;cas++)
    {
        int n,i,ans=1;
        scanf("%d",&n) ;
        printf("Case %lld : ", cas) ;
        printf("%lld\n", solve(n)) ;
    }
}
