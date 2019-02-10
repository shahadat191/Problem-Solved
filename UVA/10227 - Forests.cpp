#include<bits/stdc++.h>
using namespace std;
 
map<int, int> smap;
int hash_value(set<int> s){
    int hval = 0;
    int p = 1;
    for(auto c: s){
        hval = hval + (c*p)%MOD;
        hval %= MOD;
        p *= 107;
    }
    return hval;
}
 
int main(){
    int cas;
    cin>>cas;
    while (cas--) {
        int p, t;
        set<int> store[110];
        cin>>p>>t;
        getchar();
        string str;
        while (getline(cin, str) && str.size() != 0) {
            int a, b;
            stringstream s(str);
            s>>a>>b;
            store[a].insert(b);
        }
        for(int i = 1; i<=p; i++){
            int temp = hash_value(store[i]);
            smap[temp]++;
        }
        cout<<smap.size()<<endl;
        if(cas) cout<<endl;
        smap.clear();
    }
}
