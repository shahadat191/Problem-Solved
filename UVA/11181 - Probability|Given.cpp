/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 */

#include<bits/stdc++.h>
#define ms(a,b) memset(a, b, sizeof(a))
#define all(x) x.begin(),x.end()
//#define int long long
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
using namespace std;

int const N = 20;
double p[N+1], rp[N+1];
double q[N+1][N+1];
int n, r;
double solve(int pos){
    ms(q, 0);
    q[0][0] = 1.0;
    for(int i = 1; i<=n; i++){
        if(i == pos){
            q[i][0] = 0.0;
            for(int j = 1; j<=min(i,r); j++){
                q[i][j] = q[i-1][j-1]*p[i];
            }
        }
        else{
            q[i][0] = rp[i]*q[i-1][0];
            for(int j = 1; j<=min(i, r); j++){
                q[i][j] = q[i-1][j-1]*p[i] + q[i-1][j]*rp[i];
            }
        }
    }
    return q[n][r];
}
int32_t main(){
    //input;
    int cas = 1;
    while(cin>>n>>r){
        ms(q, 0);
        if(n == 0 && r == 0) break;
        for(int i = 1; i<=n; i++){
            cin>>p[i];
            rp[i] = 1.0 - p[i];
        }
        double res = solve(0);
        printf("Case %d:\n", cas++);
        for(int i = 1; i<=n; i++){
            double tres = solve(i);
            printf("%.6lf\n", tres/res);
        }
        
    }
   
}
