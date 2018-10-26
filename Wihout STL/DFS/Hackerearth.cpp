/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 Problem-Link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
 */
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
} *head[1010], *tail[1010];
int visit[1010], label[1010];

void insert(int x, int y){
    node* temp = new node();
    temp->data = y;
    temp->next = NULL;
    
    if(head[x] == NULL){
        head[x] = temp;
        tail[x] = temp;
    }
    else{
        node *curr = new node();
        curr = tail[x];
        curr->next = temp;
        tail[x] = temp;
    }
}
void show(int x){
    node* curr = head[x];
    while (curr != NULL) {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}
void setnull(int m){
    for(int i = 1; i<=m; i++){head[i] = NULL;tail[i] = NULL;
}

}
void dfs(int n){
    visit[n] = 1;
    node* curr = head[n];
    while (curr != NULL) {
        int temp = curr->data;
        if(!visit[temp]){
            label[temp] = label[n]+1;
            dfs(temp);
        }
        curr = curr->next;
    }
    
}

int main(){
    int m;
    cin>>m;
    setnull(m);
    for(int i = 1; i<=m-1; i++){
        int x, y;
        cin>>x>>y;
        insert(x,y);
        insert(y,x);
    }
    
    int girl, gi[1010];
    cin>>girl;
    for(int i = 1; i<=girl; i++){
        cin>>gi[i];
    }
    dfs(1);
    
    int mn = 1010;
    int loc = 1010;
    for(int i = 1; i<=girl; i++){
        if(mn >= label[gi[i]]){
            if(mn == label[gi[i]]){
                loc = gi[i] > loc ? loc : gi[i];
            }
            else{
                mn = label[gi[i]];
                loc = gi[i];
            }
        }
    }
    cout<<loc<<endl;
    
}
