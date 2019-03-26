#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define ms(a,b) memset(a, b, sizeof(a))
//#define int long long
#define sc(n) scanf("%d", &n)
#define printcas(cas) printf("Case #%d: Dilbert should drink beverages in this order:", cas++)
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


int indeg[N];
map<string, int> smap;
map<int, string> kmap;
vector<int> store[N];

void clear(int n){
    for(int i = 1; i<=n; i++)
        store[i].clear();
}
int32_t main(){
    //input;
    int n, cas = 1;
    while(cin>>n){
        smap.clear(); kmap.clear();
        for(int i = 1; i<=n; i++){
            string str;
            cin>>str;
            smap[str] = i;
            kmap[i] = str;
        }
        int m;
        cin>>m;
        for(int i = 1; i<=m; i++){
            string a, b;
            cin>>a>>b;
            int c = smap[a];
            int d = smap[b];
            store[c].push_back(d);
            indeg[d]++;
        }
        priority_queue<int> S;
        for(int i = 1; i<=n; i++){
            if(!indeg[i])
                S.push(-i);
        }
        vector<int> save;
        while(!S.empty()){
            int top = -S.top();
            save.push_back(top);
            S.pop();
            for(auto c: store[top]){
                indeg[c]--;
                if(!indeg[c])
                    S.push(-c);
            }
        }
        
        printcas(cas);
        for(int i = 0; i<save.size(); i++){
            cout<<" "<<kmap[save[i]];
        }
        cout<<"."<<endl<<endl;
        clear(n);
        
    }
}

