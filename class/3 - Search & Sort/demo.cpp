#include <iostream>
using namespace std;

struct node {
    int info;
    node *next;
};

void init(node *head){
    head = NULL;
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void add(node *&head,int x){
    node *p = createNode(x);
    if(head ==NULL ){
        head = p;
    } else {
        p->next = head;
        head = p;
    }
}

void output(node *head){
    while(head!=NULL){
        cout << head->info << " ";
        head = head->next;
    }
}

int main(){
    // node *head;
    // init(head);
    // add(head,10);

    // add(head,20);
    // add(head,30);
    // add(head,40);
    // add(head,50);
    // output(head);

    return 1;
}