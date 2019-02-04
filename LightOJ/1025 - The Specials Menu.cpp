#include<bits/stdc++.h>
#define int long long
#define ll long long
#define all(x) x.begin(),x.end()
using namespace std;

string str;
int dp[100][100], visit[100][100];
int cas = 1;
int fun(int a, int b){
    if(a > b) return 0;
    if(a == b) return 1;
    if(visit[a][b] == cas)
        return dp[a][b];
    int ret = 0;
    if(str[a] == str[b]){
        ret = fun(a+1, b-1);
        ret += 1;
    }
    ret += fun(a+1, b) + fun(a, b-1) - fun(a+1, b-1);
    visit[a][b] = cas;
    return dp[a][b] = ret;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        cin>>str;
        printf("Case %lld: %lld\n", cas++, fun(0, str.size()-1));
    }
}
