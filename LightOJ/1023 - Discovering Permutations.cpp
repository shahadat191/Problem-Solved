
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
//#define int  long long
#define nl printf("\n")
#define print(cas) printf("Case %d:", cas)
#define input freopen("input.txt","rt", stdin)
#define output freopen("output.txt","wt", stdout)
#define sc(n) scanf("%d", &n)
#define sc2(a,b) scanf("%d %d", &a, &b)

using namespace std;

int const N = 30;
int n,k;
string str;
char arr[N];
int visit[N];

void fun(int koto){
    if(koto == n){
        if(k > 0){
            for(int i = 0; i<str.size(); i++)
             printf("%c", arr[i]);
            nl;
        }
        k--;
        return;
    }
    for(int i = 0; i<str.size(); i++){
        if(visit[i] == 0){
            visit[i] = 1;
            arr[koto] = str[i];
            fun(koto+1);
            visit[i] = 0;
        }
        if(k == 0)
            break;
    }
}

void solve(int cas){
    memset(visit, 0, sizeof visit);
    sc2(n,k);
    print(cas);nl;
    string stemp;
    for(int i = 0; i<n; i++){
        stemp.push_back(i+65);
    }
    str = stemp;
    fun(0);
}

int32_t main(){
    int t, cas = 0;
    sc(t);
    while(t--){
        cas++;
        solve(cas);
    }

}

