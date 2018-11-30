
/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */
 
#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846264338
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define output freopen("/Users/shahadat/Desktop/output.txt", "w", stdout)

#define ms(a,b) memset(a, b, sizeof(a))
//#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int const N = 70;
map<int, pair<int,int> > smap;
int visit[N][N];
int32_t main(){
    IOS;
    smap[0] = make_pair(0, 1);
    smap[90] = make_pair(1, 0);
    smap[180] = make_pair(0, -1);
    smap[270] = make_pair(-1, 0);
    
    int t;
    cin>>t;
    int cas = 1;
    while (t--) {
        ms(visit, 0);
        int x,y;
        cin>>x>>y;
        string str;
        cin>>str;
        
        visit[x][y]++;
        int deg = 0;
        int sum = 0;

        for(int i = 0; i<str.size(); i++){
            if(str[i] == 'F'){
                x += smap[deg].first;
                y += smap[deg].second;
                visit[x][y]++;
                if(visit[x][y] == 2)
                    sum++;
            }
            else if(str[i] == 'L'){
                deg -= 90;
                if(deg < 0) deg += 360;
            }
            else if(str[i] == 'R'){
                deg += 90;
                deg %= 360;
            }
        }
        
        
        printf("Case #%d: %d %d %d\n", cas++,x,y,sum);
        
    }
}
