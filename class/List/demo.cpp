#include <bits/stdc++.h>
using namespace std;


struct node {
    int info;
    node *next;
};

void init (node *head){
    head = NULL;
}

void output(node *head){
    node *p = head;
    while(p!=NULL){
        cout << p->info << " ";
        p = p->next;
    }
}

node* makeNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void insertFirst(node *&head,int x){
    node *p = makeNode(x);
    if(head == NULL){
        head = p;
    } else{
        p->next = head;
        head = p;
    }
}

int len(node *head){
    int cnt =0;
    while(head!=NULL){
        ++cnt;
        head = head->next;
    }
    return cnt;
}

void insertMid(node *&head,int x,int k){
    int n = len(head);
}

int main(){

    node *head;
    insertFirst(head,10);
    insertFirst(head,20);
    insertFirst(head,30);
    // output(head);
    cout <<  len(head);
    return 0;
}