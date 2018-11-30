
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
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int const N = 70;
map<int, pair<int,int> > smap;
int visit[N][N];
int r[10];
int32_t main(){
    vector<int> num;
    num.push_back(1);

    int cont = 0;
    while (num.size() < 1500) {
        cont++;
        int temp;
        while (num[r[2]]*2 <= num.back()) {
            r[2]++;
        }
        temp = 2 * num[r[2]];
        while(num[r[3]]*3 <= num.back()){
            r[3]++;
        }
        temp = min(temp, 3*num[r[3]]);
        
        while(num[r[5]]*5 <= num.back()){
            r[5]++;
        }
        temp = min(temp, 5*num[r[5]]);
        num.push_back(temp);
    }
    printf("The 1500'th ugly number is %lld.\n", num.back());
}
