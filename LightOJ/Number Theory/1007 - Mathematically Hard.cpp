#include<bits/stdc++.h>
//#define int long long
#define sc(n) scanf("%d", &t)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define print(cas) printf("Case %d: ", cas)
#define input freopen("input.txt","rt", stdin)
#define output freopen("output.txt","wt", stdout)
using namespace std;

int const N = 5000000;
int const MOD = 1e9 + 9;

unsigned long long tfunc[N+5];
void calc(){
    for(int i = 2; i<=N; i++){
        tfunc[i] = i;
    }
    for(int i = 2; i<=N; i++){
        if(tfunc[i] != i) continue;
        for(int j = i; j<=N; j+=i){
            tfunc[j] -= tfunc[j]/i;
        }
    }
    for(int i = 2; i<=N; i++){
        tfunc[i] *= tfunc[i];
        tfunc[i] += tfunc[i-1];
    }
}

void solve(int cas){
    int a, b;
    sc2(a,b);
    print(cas);
    printf("%llu\n", tfunc[b]-tfunc[a-1]);
}

int32_t main(){
    calc();
    int t, cas = 0;
    sc(t);
    while(t--){
        cas++;
        solve(cas);
    }
}
