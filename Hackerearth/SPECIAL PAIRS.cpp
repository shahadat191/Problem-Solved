#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<assert.h>
#include<queue>
#include<cstring>

using namespace std;
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define valid(x,y) x>=0 && y>=0 && x<4 && y<4
int Set(int n, int pos){return n |= (1 << pos);}
bool Check(int n, int pos){return (n >> pos) & 1;}

int const N = 2e6 +10;
int save[N];
int ar[N];

void solve();
int main(){
    input;
    int t;
    scanf("%d", &t);
    while(t--){
        memset(save, 0, sizeof(save));
        solve();
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &ar[i]);
        save[ar[i]]++;
    }
    for(int i = 0; i < 20; i++){
        for(int mask = 0; mask < (1 << 20); mask++){
            if(mask & (1 << i))
                save[mask] += save[mask ^(1 << i)];
        }
    }
    
    long long res = 0;
    for(int i = 0; i < n; i++){
        int temp = ar[i];
        int req = 0;
        for(int i = 0; i < 20; i++){
            if(1 & (temp >> i)) continue;
            req |= (1 << i);
        }
        res += save[req];
    }
    cout << res << endl;
}
