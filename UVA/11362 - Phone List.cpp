
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
#include<functional>
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

#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define output freopen("/Users/shahadat/Desktop/output.txt", "w", stdout)

#define ms(a,b) memset(a, b, sizeof(a))

using namespace std;

vector<string> str;
struct node{
    bool save;
    node* next[12];
    node(){
        save = 0;
        for(int i = 0; i<10; i++)
            next[i] = NULL;
    }
    
} *root;

void del(node* curr){
    for(int i = 0; i<10; i++){
        if(curr->next[i] != NULL)
            del(curr->next[i]);
    }
    delete curr;
}

int main(){
    int t;
    sc(t);
    while (t--) {
        str.clear();
        root = new node();
        
        int n;
        sc(n);
        for(int i = 0; i<n; i++){
            string temp;
            cin>>temp;
            str.push_back(temp);
        }
        sort(str.begin(), str.end());
        
        bool flag = true;
        for(int i = 0; i<str.size(); i++){
            string temp = str[i];
            node* curr = root;
            
            for(int j = 0; j<temp.size(); j++){
                int te = temp[j] - 48;
                if(curr->next[te] == NULL)
                    curr->next[te] = new node();
                if(curr->save == 1)
                    flag = false;
                curr = curr->next[te];
            }
            
            if(curr->save == 1)
                flag = false;
            curr->save = 1;
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        del(root);
    }
}
