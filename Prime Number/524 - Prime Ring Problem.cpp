/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */
 
#include<bits/stdc++.h>
using namespace std;

#define ms(a,b) memset(a, b, sizeof(a))
//#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int const N = 100;
bool prime[N+5];
void sieve(){
    ms(prime, true);
    prime[0] = false;
    prime[1] = false;
    for(int i = 4; i<=N; i+=2)
        prime[i] = false;
    for(int i = 3; i*i<=N; i+=2){
        if(prime[i]){
            for(int j = i*i; j<=N; j+=i)
                prime[j] = false;
        }
    }
}

int n;
int res[100];
int visit[100];

void pass(int pos){
    if(pos == n){
        if(prime[1 + res[pos]]){
            printf("1");
            for(int i = 2; i<=n; i++)
                printf(" %d", res[i]);
            printf("\n");

        }
        return;
    }
    for(int i = 2; i<=n; i++){
        int temp = res[pos] + i;
        if(prime[temp] && visit[i] == 0){
            res[pos + 1] = i;
            visit[i] = 1;
            pass(pos+1);
            visit[i] = 0;
        }
    }
}


int32_t main(){
    IOS;
    sieve();
    int cas = 1;
    while (scanf("%d", &n) != EOF) {
        if(cas > 1)
            printf("\n");
        printf("Case %d:\n", cas++);
        ms(visit, 0);
        
        res[1] = 1;
        pass(1);
        
    }
    
}
