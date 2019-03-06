#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define ms(a,b) memset(a, b, sizeof(a))
//#define int long long
#define all(a) (a.begin()),(a.end())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define D(x) cout << #x << " = " << x << endl
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define valid(x,y) x>=0 && y>=0 && x<n && y<n
#define output freopen("/Users/shahadat/Desktop/output.txt", "w", stdout)

using namespace std;
int const N = 100;
int const MOD = 1e9 + 7;

map<string, int> s;
map<int, string> ks;

set<int> store[N], restore[N];
int visit[N];
stack<int> sst;
vector<vector<int> > res;

void dfs(int pos){
    visit[pos] = 1;
    for(auto c: store[pos]){
        if(visit[c] == 0){
            dfs(c);
        }
    }
    sst.push(pos);
}

void dfs2(int pos){
    visit[pos] = 1;
    res.back().push_back(pos);
    for(auto c: restore[pos]){
        if(visit[c] == 0){
            dfs2(c);
        }
    }
}
void clear(int n){
    for(int i = 0; i<N; i++){
        store[i].clear();
        restore[i].clear();
    }
    ms(visit, 0);
    s.clear();
    ks.clear();
    res.clear();
}
int32_t main(){
    
    int n, m, cas = 1;
    while(cin>>n>>m){
        clear(n);
        int idx = 1;
        if(m == 0 && n == 0) break;
        if(cas > 1) cout<<endl;
        
        for(int i = 0; i<m; i++){
            string a, b;
            cin>>a>>b;
            //cout<<a<<" "<<b<<endl;
            if(!s.count(a)){
                s[a] = idx;
                ks[idx] = a;
                idx++;
            }
            if(!s.count(b)){
                s[b] = idx;
                ks[idx] = b;
                idx++;
            }
            
            int p = s[a];
            int q = s[b];
            store[p].insert(q);
            restore[q].insert(p);
        }
        ms(visit, 0);
        
        for(int i = 1; i<=n; i++){
            if(visit[i] == 0){
                dfs(i);
            }
        }
        
        ms(visit, 0);
        
        while(!sst.empty()){
            int temp = sst.top();
            if(visit[temp] == 0){
                res.emplace_back();
                dfs2(temp);
               
                
            }            
            sst.pop();
        }
        
        printf("Calling circles for data set %d:\n", cas++);
        for(auto c: res){
            for(int i = 0; i<c.size()-1; i++){
                cout<<ks[c[i]]<<", ";
            }
            cout<<ks[c.back()]<<endl;
        }
        
    }
}
