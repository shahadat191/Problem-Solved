#include<bits/stdc++.h>
using namespace std;
#define int long long
#define input freopen("input.txt", "rt", stdin)
#define output freopen("output.txt", "wt", stdout)

int const N = 35000;
bool prime[N+5];
vector<int> store;
void sieve(){
    memset(prime, true, sizeof prime);
    for(int i = 2; i<=N; i++){
        if(!prime[i])
            continue;
        for(int j = i*i; j<=N; j+=i){
            prime[j] = false;
        }
        store.push_back(i);
    }
}

int32_t main(){
    sieve();
    string str;
    while(getline(cin, str) && str != "0"){
        istringstream s(str);
        int res = 1;
        int b, p;
        while(s >> b >> p){
            res *= pow(b, p);
        }
        res--;

        map<int,int> smap;
        for(int i = 0; store[i]*store[i]<=res; i++){
            if(res % store[i] == 0){
                while(res % store[i] == 0){
                    res /= store[i];
                    smap[store[i]]++;
                }
            }
        }
        if(res > 1)
            smap[res]++;

        bool flag = true;
        for(auto it = smap.rbegin(); it != smap.rend(); it++){
        	auto c = *it;
        	if(flag) flag = false;
        	else cout<<" ";
            cout<<c.first<<" "<<c.second;
        }
        cout<<endl;
    }


}

