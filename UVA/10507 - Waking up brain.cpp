/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 */

#include<bits/stdc++.h>
//#define int long long
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
using namespace std;

map<char, int> smap;
int32_t main(){
    int n, m;
    while(cin>>n>>m){
        smap.clear();
        string str;
        cin>>str;
        for(int i = 0; i<str.size(); i++) smap[str[i]]++;
        vector<string> con;
        for(int i = 1; i<=m; i++){
            string temp;
            cin>>temp;
            con.push_back(temp);
        }
        
        bool flag = true;
        for(int i = 0; i<=n; i++){
            if(smap.size() == n){
                printf("WAKE UP IN, %d, YEARS\n", i);
                flag = false;
                break;
            }
            map<char,int> tmap;
            for(int j = 0; j<con.size(); j++){
                char a = con[j][0];
                char b = con[j][1];
                if(smap.count(a)  && smap.count(b)) continue;
                if(smap.count(a)) tmap[b]++;
                if(smap.count(b)) tmap[a]++;
            }
            for(auto c: tmap){
                if(c.second >= 3)
                    smap[c.first]++;
            }
        }
        if(flag)
            printf("THIS BRAIN NEVER WAKES UP\n");

    }
    
    
}
