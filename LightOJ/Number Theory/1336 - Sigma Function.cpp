#include<bits/stdc++.h>
#define ll long long
#define ms(a,b) memset(a, b, sizeof a)
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define output freopen("/Users/shahadat/Desktop/output.txt", "w", stdout)
using namespace std;

ll const N = 1000000;
bool prime[N+5];
vector<int> store;
vector<ll> restore;
void sieve(){
    ms(prime, true);
    for(ll i = 3; i<=N; i++){
        if(!prime[i]) continue;
        ll temp = i*i;
        while(temp <= N){
            prime[temp] = false;
            temp *= i;
        }
    }
    for(int i = 3; i<=N; i+=2){
        if(prime[i]) store.push_back(i);
    }
    ll i = 1;
    while(1){
        if(i > N*N) break;
        restore.push_back(i);
        i *= 2;
    }
}

int32_t main(){
    sieve();
    int t, cas = 0;
    scanf("%d", &t);
    while(t--){
        cas++;
        ll n;
        ll sum = 0;
        scanf("%lld", &n);
        vector<ll> save;
        for(int i = 0; i<store.size(); i++){
            ll temp = 1;
            for(int j = 1; ; j++){
                temp *= store[i];
                if(temp > n)
                    break;
                if(j % 2 == 0){
                    save.push_back(temp);
                }
            }
        }
        for(int i = 0; i<save.size(); i++){
            ll temp = save[i];
            for(int k = 0; k<restore.size(); k++){
                if(temp*restore[k] > n)
                    break;
                sum++;
            }
        }
        for(int i = 0; i<restore.size(); i++){
            if(restore[i] > n)
                break;
            sum++;
        }
        printf("Case %d: %lld\n", cas, n-sum);
    }
}


