#include<bits/stdc++.h>
#define ll long long
#define ms(a,b) memset(a, b, sizeof a)
using namespace std;

ll const N = 1000000;

vector<ll> store;
map<ll,int> smap;
map<ll,int>::iterator it;
bool prime[N+5];

void prgen(){
    ms(prime, true);
    for(ll i = 4; i<=N; i+=2) prime[i] = false;
    for(ll i = 3; i*i<=N; i+=2){
        if(prime[i]){
            for(ll j = i*i; j<=N; j+=i){
                prime[j] = false;
            }
        }
    }
    for(int i = 2; i<=N; i++)
        if(prime[i])
            store.push_back(i);
}
ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int32_t main(){
    prgen();
    int t, cas = 0;
    cin>>t;
    while(t--){
        smap.clear();
        cas++;
        ll a,b,l;
        scanf("%lld %lld %lld", &a, &b, &l);
        ll ab = (a*b)/gcd(a,b);
        for(int i = 0; i< store.size(); i++){
            if(store[i]*store[i] > l)
                break;
            while(l % store[i] == 0){
                smap[store[i]]++;
                l /= store[i];
            }
        }
        if(l > 1)
            smap[l]++;
        ll res = 1;
        for(it = smap.begin(); it!=smap.end(); it++){
            ll t1 = it->first;
            int t2 = it->second;
            ll t = pow(t1, t2);
            if(ab % t != 0)
                res *= t;
            while(ab % t1 == 0){
                ab /= t1;
                t2--;
                if(t2 == 0)
                    break;
            }
        }
        if(ab == 1)
            printf("Case %d: %lld\n", cas, res);
        else
            printf("Case %d: impossible\n", cas);
    }
}

