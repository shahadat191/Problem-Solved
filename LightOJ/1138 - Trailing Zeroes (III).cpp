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

int fact(int num, int div){
    int sum = 0;
    while(num != 0){
        sum += num/div;
        num /= div;
    }
    return sum;
}
int zero(int num){
  int tw = fact(num, 2);
  int fi = fact(num, 5);
  return fi < tw ? fi : tw;
}

int solve(int cas){
    int n;
    cin>>n;
    int left = 1, right = 1e9;
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        int temp = zero(mid);
        if(temp >= n) right = mid - 1;
        else left = mid + 1;
    }
    print(cas);
    if(zero(left) == n) cout<<left<<endl;
    else cout<<"impossible"<<endl;
}

int32_t main(){
    int t, cas = 0;
    cin>>t;
    while(t--){
        cas++;
        solve(cas);
    }
}
