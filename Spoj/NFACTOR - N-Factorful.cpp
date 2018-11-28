/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */
#include<bits/stdc++.h>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

int fx[]= {0,0,-1,1};
int fy[] = {1,-1,0,0};

/*
 ll fx[]= {0, 1, 0, 0};
 ll fy[]= {1, 0, -1, -1};
 
 ll dx[]= {-1, 1, 0, 0, 1, 1, -1, -1};
 ll dy[]= {0, 0, 1, -1, 1, -1, -1, 1};
 
 ll cx[] = {1,1,2,2,-1,-1,-2,-2};
 ll cy[] = {2,-2,1,-1,2,-2,1,-1};
 */

//valid
#define valid(x,y) x>=0 && y>=0 && x<n && y<n

#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)

#define sc2(m,n) scanf("%d %d",&m, &n)
#define scl2(m,n) scanf("%lld %lld",&m, &n)

#define pr(n) prllf("%d",n)
#define prln(n) prllf("%d\n",n)
#define prsp(n) prllf("%d ",n)
#define newline printf("\n")

#define PI 3.14159265358979323846264338
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define output freopen("/Users/shahadat/Desktop/output.txt", "w", stdout)

#define ms(a,b) memset(a, b, sizeof(a))
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int const N = 1000000;
int prime[N+5];
void sieve(){
    for(int i = 2; i<=N; i++){
        if(prime[i] == 0){
            for(int j = i; j<=N; j+=i){
                prime[j]++;
            }
        }
    }
}
vector<int> store[11];
int32_t main(){
    IOS;
    sieve();
    for(int i = 1; i<=N; i++){
        int idx = prime[i];
        store[idx].push_back(i);
    }
    int t;
    cin>>t;
    while (t--) {
        int a,b,n;
        cin>>a>>b>>n;
        int right = upper_bound(store[n].begin(), store[n].end(), b) - store[n].begin();
        right--;
        int left = lower_bound(store[n].begin(), store[n].end(), a) - store[n].begin();
        int res = right - left + 1;
        cout<<res<<endl;
    }
    
}
