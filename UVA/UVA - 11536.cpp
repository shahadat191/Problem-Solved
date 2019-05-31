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

int const N = 2e5;
int cas = 1;
int ar[1000005] = {1,2,3};

void solve(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 3; i < n; i++){
        ar[i] = (ar[i - 1] + ar[i - 2] + ar[i - 3]) % m + 1;
    }
    
    int l = 0, r = 0;
    int cnt = 0;
    
    int save[105] = {};
    int res = 1e8;
    while (r < n) {
        if(cnt == k){
            res = min(res, r - l);
            if(ar[l] <= k){
                save[ar[l]]--;
                if(save[ar[l]] == 0) cnt--;
            }
            l++;
        }
        else{
            if(ar[r] <= k){
                if(save[ar[r]] == 0) cnt++;
                save[ar[r]]++;
            }
            r++;
        }
        
    }
    printf("Case %d: ", cas++);
    if(res > n){
        printf("sequence nai\n");
        return;
    }
    printf("%d\n", res);

}


int main(){
   input;
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
}
