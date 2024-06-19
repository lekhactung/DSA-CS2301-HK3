#include <bits/stdc++.h>
using  namespace std;

struct node {
    int info;
    node *prev,*next;
};

node* createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = p->prev = NULL;
    return p;
}

void output(node *head){
    while(head!=NULL){
        cout << head->info << " ";
        head = head->next;
    }
}

void insertFirst(node *&head,int x){
    node *p = createNode(x);
    
    p->next = head;

    if(head!=NULL){
        head->prev = p;
    }

    head = p;
}

int main(){

    node *head;
    insertFirst(head,10);
    insertFirst(head,20);
    insertFirst(head,30);

    output(head);

    return 0;
}