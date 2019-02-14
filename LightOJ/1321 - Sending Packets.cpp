/*
Shahadat Hossain
I.C.T Department
Comilla University
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct demo{
    int dest;
    double pro;
    bool operator < (const demo& b)const{
        return pro < b.pro;
    }
};
vector<demo> store[102];
double res[102];
int parent[102];
void bfs(){
    for(int i = 1; i<=100; i++) res[i] = 0.00;
    priority_queue<demo> s;
    s.push({1, 1.0});
    while (!s.empty()) {
        int temp = s.top().dest;
        double pro = s.top().pro;
        s.pop();
        if(res[temp] > pro) continue;
        for(int i = 0; i<store[temp].size(); i++){
            int t2 = store[temp][i].dest;
            if(parent[temp] == t2) continue;
            parent[t2] = temp;
            double pro2 = store[temp][i].pro;
            if(res[t2] < pro2*pro){
                res[t2] = pro2*pro;
                s.push({t2, res[t2]});
            }
        }
    }
    
}

void clear(){
    for(int i = 1; i<=101; i++){
        store[i].clear();
        parent[i] = 0;
    }
}

int32_t main(){
    int t, cas = 1;
    cin>>t;
    while (t--) {
        clear();
        int n, m, s, k;
        cin>>n>>m>>s>>k;
        for(int i = 1; i<=m; i++){
            int a, b, ti;
            cin>>a>>b>>ti;
            a++;b++;
            double rt = ti/100.0;
            store[a].push_back({b, rt});
            store[b].push_back({a, rt});
        }
        bfs();
        double ret = k/res[n];
        ret *= 2*s;
        printf("Case %lld: %lf\n", cas++, ret);
    }
}
