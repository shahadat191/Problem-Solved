#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define ms(a,b) memset(a, b, sizeof(a))
#define int long long
#define sc(n) scanf("%d", &n)
#define printcas(cas) printf("Case %d:", cas++)
#define nl printf("\n")
#define pr(n) printf("%d\n", n)
#define sc2(n, m) scanf("%d %d", &n, &m)
#define pb push_back
#define all(a) (a.begin()),(a.end())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define D(x) cout << #x << " = " << x << endl
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define valid(x,y) x>=0 && y>=0 && x<n && y<n
#define output freopen("/Users/shahadat/Desktop/output.txt", "w", stdout)

using namespace std;
int const N = 110;
int const MOD = 1e15 + 7;
int inf = 1e15;

vector<int> store[N];
int visit[N];
void clear(int n){
    for(int i = 1 ; i<=n; i++)
        store[i].clear();
}
void dfs(int pos){
    for(auto c: store[pos]){
        if(c == pos){
            visit[c] = 1;
            continue;
        }
        if(visit[c] == 0){
            visit[c] = 1;
            dfs(c);
        }
    }
}

int32_t main(){
    input;
    int n;
    while(cin>>n && n!=0){
        int u;
        while(cin>>u && u!=0){
            int v;
            while(cin>>v && v!=0)
                store[u].push_back(v);
        }
        int q;
        cin>>q;
        while(q--){
            int uu;
            cin>>uu;
            ms(visit, 0);
            dfs(uu);
            vector<int> save;
            for(int i = 1; i<=n; i++)
                if(!visit[i])
                    save.push_back(i);
            cout<<save.size();
            for(int i = 0; i<save.size(); i++){
                cout<<" "<<save[i];
            }
            cout<<endl;
        }
        clear(n);
    }
}

