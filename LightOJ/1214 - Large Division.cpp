#include<bits/stdc++.h>
#define int long long
#define print(cas) printf("Case %d: ", cas)
using namespace std;

bool bigDivision(string str, int div){
    reverse(str.begin(), str.end());
    string res;
    int carr = 0, temp = 0;
    while (str.size()> 0) {
        temp = str.back() - '0';
        temp += (carr*10);
        res.push_back((temp/div)+48);
        carr = temp%div;
        str.pop_back();
    }
    if(carr == 0) return 1;
    else return 0;
}

void solve(int cas){
    string str;
    int n;
    cin>>str>>n;
    str = str.substr(str.find_first_not_of('-'));
    print(cas);
    if(!bigDivision(str, n)) cout<<"not ";
    cout<<"divisible"<<endl;
}

int32_t main(){
    int t, cas = 0;
    cin>>t;
    while(t--){
        cas++;
        solve(cas);
    }
}
