/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */
#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846264338
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define output freopen("/Users/shahadat/Desktop/output.txt", "w", stdout)

#define ms(a,b) memset(a, b, sizeof(a))
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int const N = 1000000;
bool prime[N+5];
vector<int> store;
void sieve(){
    ms(prime, true);
    prime[0] = false;
    prime[1] = false;
    for(int i = 4; i<=N; i+=2)
        prime[i] = false;
    for(int i = 3; i*i<=N; i+=2){
        if(prime[i]){
            for(int j = i*i; j<=N; j+=i)
                prime[j] = false;
        }
    }
    for(int i = 3; i<=N; i+=2){
        if(prime[i] == true)
            store.push_back(i);
    }
}

int32_t main(){
    IOS;
    sieve();
    int n;
    n = 6;
    while (cin>>n && n!=0) {
        bool flag = false;
        for(int i = 0; i<store.size(); i++){
            if(store[i] >= n)
                break;
            if(prime[n-store[i]]){
                flag = true;
                printf("%lld = %lld + %lld\n", n, store[i], n-store[i]);
                break;
            }
        }
    }
}
