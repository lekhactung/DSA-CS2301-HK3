#include <iostream>
using namespace std;

struct node {
    int info;
    node *next;
};

void init(node *&head){
    head = NULL;
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

bool isEmpty(node *head){
    return head == NULL;
}

void push(node *&head,int x){
    node *p = createNode(x);
    if(isEmpty(head)){
        head = p;
    } else{
        p->next = head;
        head = p;
    }
}

node* pop (node *&head){
    if(!isEmpty(head)){
        node *p = head;
        node *plast = nullptr;
        while(!isEmpty(p->next)){
            plast = p;  
            p=p->next;
        }
        plast->next = NULL;
        return p;
    }
    return nullptr;
}

void output(node *head){
    while(!isEmpty(head)){
        cout << head->info << " ";
        head = head->next;  
    }
    cout << endl;
}

int main(){
    node *head;
    init(head);
    push(head,10);
    push(head,20);
    push(head,30);
    push(head,40);
    // cout << pop(head)->info << endl;
    output(head);
    cout << pop(head)->info << endl;
    cout << pop(head)->info << endl;



    return 1;
}