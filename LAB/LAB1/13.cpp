#include <iostream>
using namespace std;

struct node{
    int info;
    node *next;
};  

void init(node *&head){
    head = NULL;
}

bool isEmpty(node *head){
    return head == NULL;
}

int peek(node *head){
    if(!isEmpty(head)){
        return head->info;
    } else{
        exit(1);
    }
}

node *createNode (int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void push(node *&head,int x){
    node *p = createNode(x);
    if(isEmpty(head)){
        head = p;
    } else {
        p->next = head;
        head = p;
    }
}

node* pop(node *&head){
    node *p = head;
    if(head!=NULL){
        head = head->next;
        p->next= NULL;
        return p;
    }
    return nullptr;
}

void output(node *head){
    while(!isEmpty(head)){
        cout << head->info  << " ";
        head = head->next;
    }
    cout << endl;
}

void dectobin(int n){
    node *head;
    init(head);
    while(n!=0){
        int tmp = n%2;
        push(head,tmp);
        n/=2;
    }

    while(!isEmpty(head)){
        cout << pop(head)->info;
    }
}

int main(){
    // node *head;
    // init(head);
    // push(head,10);
    // push(head,20);
    // push(head,30);
    // push(head,40);
    // output(head);
    dectobin(13);
    return 1;
}