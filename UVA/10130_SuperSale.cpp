/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */

#include<bits/stdc++.h>

#define sc2(m,n) scanf("%d %d",&m, &n)
#define sc3(m,n,o) scanf("%d %d %d",&m, &n, &o)
#define pb push_back
#define mp make_pair
#define fs first
#define se second
#define pi 2*acos(0)
#define PI 3.14159265358979323846264338
#define modulo 1000000007
#define SMA 300010
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define output freopen("/Users/shahadat/Desktop/output.txt", "w", stdout)
#define ms(a,b) memset(a, b, sizeof(a))
#define sc(n) scanf("%d",&n)
#define scs(n) scanf("%s",&n)
#define loop(i,n) for(int i = 0; i<n; i++)
#define nloop(i,n) for(int i = 1; i<=n; i++)
#define prln(n) printf("%d\n",n)
#define prsp(n) printf("%d ",n)
#define pr(n) printf("%d ",n)
#define prs(n) printf("%s",n)

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;


//-----Code Starts Here-------

int n;
int cost[1010], weight[1010];
int dp[1010][35];

int fun(int i, int w){
    if(i == n) return 0;
    if(dp[i][w] == -1){
        int p1 = 0;
        if(w >= weight[i]){
            p1 = cost[i] + fun(i + 1, w - weight[i]);
        }
        int p2 = fun(i + 1, w);
        dp[i][w] = max(p1, p2);
        return dp[i][w];
    }
    else return dp[i][w];
}
int main(){    
    int t;
    sc(t);
    while (t--) {
        ms(dp, -1);
        sc(n);
        for(int i = 0; i<n; i++){
            sc2(cost[i], weight[i]);
        }
        int g;
        sc(g);
        
        ll sum = 0;
        for(int i = 0; i<g; i++){
            int temp;
            sc(temp);
            sum += fun(0, temp);
        }
        printf("%lld\n", sum);
    }
}
