#include<iostream>
#include<map>
#include<algorithm>

using namespace std;
//#define int long long
//#define input freopen("input.txt", "rt", stdin)
//#define output freopen("output.txt", "wt", stdout)
double const pi = 3.14159265358979323846;
int const N = 15;
int const MOD = 100000007;
int const inf = 10000000;

int Set(int n, int pos){ return n | (1<<pos);}
int Reset(int n, int pos){ return n & ~(1<<pos);}
bool Check(int n, int pos){return (bool)(n&(1<<pos));}

int si[110], fi[110];

int smap[200010], tmap[200010], visit[200010];
int main(){
    //input;
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>si[i];
        cin>>fi[i];
    }

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=200000; j++) tmap[j] = -inf;
        for(int j = 0; j<=200000; j++){
            int nextpos = si[i] + j;
            int nextval = fi[i] + smap[j];
            if(visit[j] == 1)
                tmap[nextpos] = nextval;
        }

        for(int j = 0; j<=200000; j++){
            if(tmap[j] == -inf)
                continue;
            if(visit[j] == 1)
                smap[j] = max(smap[j], tmap[j]);
            else{
                visit[j] = 1;
                smap[j] = tmap[j];
            }
        }
        if(visit[si[i]+100000] == 1)
            smap[si[i]+100000] = max(fi[i], smap[si[i]+100000]);
        else{
            visit[si[i]+100000] = 1;
            smap[si[i]+100000] = fi[i];
        }
    }
    int res = 0;
    for(int i = 100000; i<=200000; i++){
        if(smap[i] > 0){
            res = max(res, i + smap[i] - 100000);
        }
    }
    cout<<res<<endl;

}
