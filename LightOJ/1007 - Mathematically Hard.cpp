#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>

#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
using namespace std;

typedef long long int ll;
int const MX = 1000000;
ll sum = 0;

unsigned long long int prime[MX+5];

void sieve(){
    for(int i = 2; i<=MX; i++){
        prime[i] = i;
    }
    for(int i = 2; i<=MX; i++){
        if(prime[i] == i){
            for(int j = i; j<=MX; j+=i){
                prime[j] -= prime[j]/i;
                sum++;
            }
        }
    }
}


int main(){
   // input;
    sieve();
    cout<<sum<<endl;
    for(int i = 2; i<=MX; i++){
        prime[i] *= prime[i];
        prime[i] += prime[i-1];
    }
    
    int t, cas = 1;
    scanf("%d", &t);
    while (t--) {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n", cas++, prime[b]-prime[a-1]);
    }
}
