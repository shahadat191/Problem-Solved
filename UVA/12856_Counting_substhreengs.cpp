/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 .
 Problem Site: UVA
 Problem No: 12856
 Problem Name: Counting substhreengs
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll res;
vector<char> store;
void calc(){
    ll arr[] = {0,0,0};
    for(int i = 0; i<store.size(); i++){
        int temp = store[i] - 48;
        ll t0 = 0, t1 = 0, t2 = 0;
        
        for(int j=0; j<3; j++){
            if(arr[j] != 0){
                int paichi = (temp+j)%3;
                if(paichi == 0) t0 += arr[j];
                else if(paichi == 1) t1 += arr[j];
                else t2 += arr[j];
            }
        }
        arr[0] = t0;
        arr[1] = t1;
        arr[2] = t2;
        arr[temp%3]++;
        
        res += arr[0];
    }
}


int main(){
    string str;
    while(cin>>str){
        res = 0;
        store.clear();
        
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]>='0' && str[i]<='9')
                store.push_back(str[i]);
            
            else{
                calc();
                store.clear();
            }
        }
        if(store.size())
            calc();
        printf("%lld\n", res);
    }
}

