#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define int unsigned long long
#define print(cas) printf("Case %d: ", cas)
#define input freopen("input.txt","rt", stdin)
#define output freopen("output.txt","wt", stdout)
using namespace std;

string dectobin(int num){
    string str;
    while(num != 0){
        str.push_back(num%2 + 48);
        num /= 2;
    }
    str.push_back('0');
    reverse(str.begin(), str.end());
    return str;
}
int bintodec(string str){
    int mul = 1, res = 0;
    while(str.size() > 0){
        int last = str.back() - 48;
        res += mul*last;
        mul *= 2;
        str.pop_back();
    }
    return res;
}
void solve(int cas){
    int n;
    cin>>n;
    string bin = dectobin(n);
    bool flag = false;
    int pos = 0;
    for(int i = bin.size()-1; i>=0; i--){
        if( bin[i] == '1' ) flag = true;
        if(flag && bin[i] == '0'){
            pos = i;
            break;
        }
    }
    bin[pos] = '1';
    bin[pos+1] = '0';
    int j = bin.size() - 1;
    for(int i = pos+2; i<=j; i++){
        swap(bin[i], bin[j]);
        j--;
    }
    print(cas);
    cout<<bintodec(bin)<<endl;
}


int32_t main(){
    input;
    output;
    int t, cas = 0;
    cin>>t;
    while(t--){
        cas++;
        solve(cas);
    }
}
