/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 */

#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    //input;
    int t, cas = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        double last = 0.0;
        double ret;
        for(int i = n-1; i>=0; i--){
            ret = 1 + (n - i)*last/(double)n;
            last = (ret * n)/(double)(n-i);
        }
        printf("Case %d: %lf\n", cas++, ret);
    }
}
