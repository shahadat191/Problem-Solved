#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define sc(n) scanf("%d", &t)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define print(cas) printf("Case %d: ", cas)
#define pr(n) printf("%d\n", n)
#define prs(n) printf("%d ", n)
#define nl printf("\n")
#define input freopen("input.txt","rt", stdin)
#define output freopen("output.txt","wt", stdout)
using namespace std;

int const N = 5000000;
int const MOD = 1e9 + 9;

void solve(int cas){
    int p,l;
    cin>>p>>l;
    p -= l;
    vector<int> res;
    print(cas);
    for(int i = 1; i*i<=p; i++){
        if(p%i == 0){
            int a = i;
            int b = p/i;
            if(a != b && a > l)
                prs(a);
            if(b > l)res.push_back(b);
        }
    }
    if(res.size() == 0){
        printf("impossible\n");
        return;
    }
    while(res.size() > 1){
        prs(res.back());
        res.pop_back();
    }
    pr(res.back());
}

int32_t main(){
    int t, cas = 0;
    cin>>t;
    while(t--){
        cas++;
        solve(cas);
    }
}
