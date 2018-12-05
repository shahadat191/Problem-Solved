#include<bits/stdc++.h>
using namespace std;
#define int long long
#define input freopen("input.txt", "rt", stdin)
#define output freopen("output.txt", "wt", stdout)
int const N = 100000000;
bool prime[N+5];
vector<int> store;

void sieve(){
    memset(prime, true, sizeof prime);
    prime[0] = false;
    prime[1] = false;
    for(int i = 4; i<=N; i+=2)
        prime[i] = false;
    for(int i = 3; i*i<=N; i+=2){
        if(!prime[i])
            continue;
        for(int j = i*i; j<=N; j+=i)
            prime[j] = false;
    }
    for(int i = 2; i<=N; i++){
        if(prime[i]){
            store.push_back(i);
        }
    }
}

void even(int n){
    int ser = 1 + (n/2);
    int pos = lower_bound(store.begin(), store.end(), ser) - store.begin();
    int first = 0, last = 0;
    for(int i = pos; i<store.size(); i++){
        first = store[i];
        last = n-store[i];
        if(prime[first] && prime[last])
            break;
    }
    if(n > 6){
        printf("%lld is the sum of %lld and %lld.\n", n, last, first);
        return;
    }
    printf("%lld is not the sum of two primes!\n", n);

}
void odd(int n){
    int last = n - 2;
    if(last > 0 && prime[last]){
        printf("%lld is the sum of 2 and %lld.\n", n, last);
        return;
    }
    printf("%lld is not the sum of two primes!\n", n);
}

void solve(int n){
    if(n%2 == 0)
        even(n);
    else
        odd(n);
}


int32_t main(){
    //input;
    //output;
    sieve();
    int n;
    while(scanf("%lld", &n) != EOF){
        solve(n);
    }

}


/*
0 & 1 prime is false, remember that
2 4 6 is not possible with goldbatch conjecture

*/
