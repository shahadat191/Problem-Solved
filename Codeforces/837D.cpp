#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define input freopen("input.txt", "rt", stdin)
//#define output freopen("output.txt", "wt", stdout)
double const pi = 3.14159265358979323846;
int const N = 210;
int const MOD = 100000007;
int const inf = 10000000;

int Set(int n, int pos){ return n | (1<<pos);}
int Reset(int n, int pos){ return n & ~(1<<pos);}
bool Check(int n, int pos){return (bool)(n&(1<<pos));}


int calc(int val, int div){
    int sum = 0;
    while(val % div == 0){sum++; val /= div;}
    return sum;
}

int five[N], two[N];
int dp[N][14000];
int32_t main(){
    //input;
    int n,k;
    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        int temp;
        cin>>temp;
        five[i] = calc(temp, 5);
        two[i] = calc(temp, 2);
    }

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i<=n; i++){
        int fi = five[i];
        int tw = two[i];

        for(int j = k-1; j>=0; j--){
            for(int m = 13000; m>=0; m--){
                if(dp[j][m] != -1){
                    if(dp[j+1][fi+m] == -1){
                        dp[j+1][fi+m] = dp[j][m] + tw;

                    }
                    else{
                        dp[j+1][m+fi] = max(dp[j+1][m+fi], tw + dp[j][m]);
                    }

                }
            }
        }
    }
    int res = 0;
    for(int i = 1; i<=13000; i++){
        if(dp[k][i] > 0){
            res = max(res, min(i, dp[k][i]));
        }
    }
    cout<<res<<endl;


}

