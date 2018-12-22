#include<bits/stdc++.h>
using namespace std;
#define int long long
#define input freopen("input.txt", "rt", stdin)
#define output freopen("output.txt", "wt", stdout)
double const pi = 3.14159265358979323846;
int const N = 210;
int const MOD = 100000007;
int const inf = 10000000;

int Set(int n, int pos){ return n | (1<<pos);}
int Reset(int n, int pos){ return n & ~(1<<pos);}
bool Check(int n, int pos){return (bool)(n&(1<<pos));}

int dp[35][905], visit[35][905];
int fun(int n, int k){
    if(k == 0)
        return 1;
    if(n < k)
        return 0;
    if(k == 1){
        return n*n;
    }
    if(visit[n][k] == 1)
        return dp[n][k];

    int p1 = fun(n - 1, k - 1);
    p1 *= n + (n - k);
    int p2 = fun(n - 1, k);

    visit[n][k] = 1;
    return dp[n][k] = p1 + p2;
}

int32_t main(){
    input;
    output;
    int t, caseno = 0;
    cin>>t;
    while(t--){
        caseno++;
        int n,k;
        cin>>n>>k;
        int res = fun(n,k);
        cout<<"Case "<<caseno<<": "<<res<<endl;
    }
}
