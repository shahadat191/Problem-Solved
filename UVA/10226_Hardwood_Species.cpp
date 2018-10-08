/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>


using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;

set<string> sset;
map<string, int> smap;
set<string>::iterator it;

int main(){
    
    int t;
    cin>>t;
    cin.ignore();
    cin.ignore();
    
    while (t--) {
        sset.clear();
        smap.clear();
        
        string str;
        int sum = 0;
        while (1) {
            getline(cin, str);
            if(str.size() == 0)
                break;
            sset.insert(str);
            smap[str]++;
            sum++;
        }
        for(it = sset.begin(); it!=sset.end(); it++){
            string temp = *it;
            double calc = ((double)smap[temp]/(double)sum)*100.00;
            printf("%s %.4lf\n", temp.c_str(), calc);
        }
        
        if(t)
            printf("\n");
    }
}

