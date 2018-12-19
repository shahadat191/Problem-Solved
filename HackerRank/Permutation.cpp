#include<bits/stdc++.h>
using namespace std;
#define int long long
#define input freopen("input.txt", "rt", stdin)
#define output freopen("output.txt", "wt", stdout)
double const pi = 3.14159265358979323846;
int const N = 15;
int const MOD = 100000007;

int Set(int n, int pos){ return n | (1<<pos);}
int Reset(int n, int pos){ return n & ~(1<<pos);}
bool Check(int n, int pos){return (bool)(n&(1<<pos));}

int n;
int arr[N];
int dp[(1<<N)+5];

bool sorted(int num){
    int beg = 0;
    for(int i = 0; i<n; i++){
        if(Check(num, i) == 1)
            continue;
        if(beg < arr[i])
            beg = arr[i];
        else
            return false;
    }
    return true;
}

bool fun(int num){
    if(sorted(num)){
        return 1;
    }

    if(dp[num] != -1)
        return dp[num];

    bool p = 0;
    for(int i = 0; i<n; i++){
        if(Check(num, i) == 0){
            p |= fun(Set(num, i));
        }
    }
    return dp[num] = !p;

}

void solve(){
    memset(dp, -1, sizeof dp);
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    bool res = fun(0);
    if(res)
        cout<<"Bob";
    else
        cout<<"Alice";
    cout<<endl;
}


int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}
