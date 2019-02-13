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

int const N = 100000;
int nc2(int n){
    return (n*(n-1))/2;
}
double fun(int n){
    if(n == 0) return 1.0;
    if(n == 1) return 0.0;
    double r1 = nc2(n+1);
    double r2 = nc2(n);
    return (r2*fun(n-2))/(double)r1;
}

int32_t main(){
    input;
    int t, cas = 1;
    cin>>t;
    while(t--){
        int tiger, dear;
        cin>>tiger>>dear;
        printf("Case %d: %.6lf\n", cas++, fun(tiger));
        
    }
}
