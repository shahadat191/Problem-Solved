#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>

#define sc(a) scanf("%d", &a)
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

int const MX = 100010;


int main(){
   // input;
    int n;
    while (scanf("%d", &n) && n!=0) {
        printf("%d = ", n);
        if(n < 0)
            printf("-1 x ");
        
        n = abs(n);
        bool flag = true;
        vector<int> store;
        while(flag){
            flag = false;
            for(ll i = 2; i*i<=n; i++){
                if(n%i == 0){
                    store.push_back((int)i);
                    flag = true;
                    n /= i;
                    break;
                }
            }
        }
        for(int i = 0; i<store.size(); i++)
            printf("%d x ", store[i]);
        printf("%d\n", n);
            
    }
    
}
