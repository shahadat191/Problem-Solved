
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

#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)

#define sc2(m,n) scanf("%d %d",&m, &n)
#define scl2(m,n) scanf("%lld %lld",&m, &n)

#define sc3(m,n,o) scanf("%d %d %d",&m, &n, &o)
#define scl3(m,n,o) scanf("%lld %lld %lld",&m, &n, &o)

#define pr(n) printf("%d",n)
#define prln(n) printf("%d\n",n)
#define prsp(n) printf("%d ",n)

#define prLL(n) printf("%lld",n)
#define prlnLL(n) printf("%lld\n",n)
#define prspLL(n) printf("%lld ",n)

#define ms(a,b) memset(a, b, sizeof(a))
using namespace std;
typedef long long ll;


ll mx;
struct node{
    int cont;
    node* next[2];
    node(){
        cont = 0;
        next[1] = NULL;
        next[0] = NULL;
    }
}*root;

void pass(string& str, int len){
    node *curr = root;
    int sum = 1;
    for(int i = 0; i<len; i++){
        int temp = str[i] - 48;
        if(curr->next[temp] == NULL)
            curr->next[temp] = new node();
        curr = curr->next[temp];
        curr->cont++;
        mx = mx > curr->cont*sum ? mx : curr->cont*sum;
        sum++;
    }
}
void del(node* curr){
    for(int i = 0; i<2; i++){
        if(curr->next[i] != NULL)
            del(curr->next[i]);
    }
    delete  curr;
}

int main(){
    int t;
    sc(t);
    while (t--) {
        mx = 0;
        root = new node();
        
        int n;
        sc(n);
        for(int i = 1; i<=n; i++){
            string temp;
            cin>>temp;
            pass(temp, (int)temp.size());
        }
        cout<<mx<<endl;
        del(root);
    }
}
