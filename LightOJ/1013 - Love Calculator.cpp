#include<bits/stdc++.h>
using namespace std;
#define int long long

int const N = 32;
int caseno = 0;
pair<int,int> dp[N][N];
int visit[N][N];
string str1,str2;

pair<int,int> fun(int a, int b){
    if(str1.size() == a && str2.size() == b)
        return make_pair(0,1);
    if(visit[a][b] == caseno){
        return dp[a][b];
    }
    pair<int,int> p = make_pair(0,0);
    if(a == str1.size()){
       p = make_pair((int)str2.size()-b, 1);
    }
    else if(b == str2.size())
        p = make_pair((int)str1.size()-a,1);
    else if(str1[a] == str2[b]){
        pair<int,int> temp = fun(a+1, b+1);
        p = make_pair(1+temp.first, temp.second);
    }
    else{
        pair<int,int> temp = fun(a+1,b);
        pair<int,int> temp2 = fun(a,b+1);
        if(temp.first == temp2.first){
            p = make_pair(1+temp.first, (temp.second+temp2.second));
        }
        else if(temp.first < temp2.first){
            p = make_pair(1+temp.first, temp.second);
        }
        else{
            p = make_pair(1+temp2.first, temp2.second);
        }
    }
    visit[a][b] = caseno;
    return dp[a][b] = p;
}

void solve(){
    caseno++;
    cin>>str1>>str2;
    pair<int,int> res = fun(0,0);
    cout<<"Case "<<caseno<<": "<<res.first<<" "<<res.second<<endl;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
