#include <iostream>
using namespace std;

struct node{
    int info;
    node *prev;
    node *next;
};

void init(node *&head){
    head->prev = NULL;
    head->next = NULL;
}

void output(node *head){
    while(head!=NULL){
        cout << head->info <<" ";
        head = head->next;
    }
}

node* createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void themdau(node *&head, int x){
    node *p = createNode(x);
    p->next = head;
    if(head!=NULL){
        head->prev = p;
    }
    head = p;
}

int main(){
    node *head;
    // init(head);
    for(int i=1;i<=10;i++){
        themdau(head,i);
    }
    output(head);
    return 0;
}