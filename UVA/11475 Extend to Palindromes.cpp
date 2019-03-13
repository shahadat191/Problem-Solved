#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define ms(a,b) memset(a, b, sizeof(a))
#define all(a) (a.begin()),(a.end())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define D(x) cout << #x << " = " << x << endl
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define valid(x,y) x>=0 && y>=0 && x<n && y<n
#define output freopen("/Users/shahadat/Desktop/output.txt", "w", stdout)
using namespace std;
int const N = 2e5 + 5;
int const MOD = 1e9 + 7;


int lps[N];
void ftable(string& pattern)
{
    int L=0,R,len=pattern.size();
    for(R=1;R<len;){
        if(pattern[R]==pattern[L]){
            lps[R]=L+1;
            L++;R++;
        }
        else{
            if(L!=0) L=lps[L-1];
            else {lps[R]=0; R++;}
        }
    }
}

int32_t main(){
    string str;
    while(cin>>str){
        string temp = str;
        reverse(all(temp));
        temp.push_back('.');
        temp += str;
        ftable(temp);
        int len = temp.size();
        int baki = str.size() - lps[len-1];
        
        for(int i = baki - 1; i>=0; i--)
            str.push_back(str[i]);
        cout<<str<<endl;  
    }
}
