#include<bits/stdc++.h>
typedef long long int ll ;
typedef unsigned long long int ull ;
const ll mod = 1e9+7 ;

ull power(ll n, ll x){
    if(x == 0) return 1 ;
    else return (n * power(n,x-1))%mod;
}

ll* reversebinformat(ll k){
    ll* binarray = new ll[64] ;
    for(ll i = 0 ; i < 64 ;i++){
        binarray[i] = 0 ;
    }
    ll cnt = 0 , n = k;
    while(k){
        binarray[cnt++] = k%2 ;     k/=2 ;
    }


    return binarray ;
}

int main(){
    ll t ;
    std::cin >> t ;

    while(t--){
        ll n,k ,res = 0;
        std::cin >> n >> k ;
        ll *ara ;
        ara =  reversebinformat(k) ;

        for(ll i = 0 ; i < 64 ; i++){
                //std::cout << ara[i]<<"  " ;
            if(ara[i]){
                res= res %mod + power(n,i)% mod  ;
                res = res % mod ;
            }
        }

        std::cout << res << '\n' ;
    }
}

