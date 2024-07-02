#include <iostream>
using namespace std;

struct node {
    int info;
    node *next;
};

void init(node *&head){
    head =NULL;
}

node *createNode(int x){
    node *p = new node ;
    p->info = x;
    p->next = NULL;
    return p; 
}

void insertFirst(node *&head,int x){
    node *p = createNode(x);
    if(head==NULL){
        head = p;
    } else {
        p->next = head;
        head = p;
    }
}

void insertLast(node *&head,int x){
    node *p = createNode(x);
    if(head == NULL){
        head = p;
    } else {
        node *plast = head;
        while(plast->next != NULL){
            plast = plast->next;
        }    
        plast->next = p;
    }
}

bool search(node *head,int x){
    if(head == NULL){
        return false;
    }
    node *p = head;
    while(p->next!=NULL){
        if(p->info == x){
            return true;
        } else {
            p=p->next;
        }
    }
    return false;
}

void del(node *&head,int x){
    if(head==NULL){
        return; 
    }
    if(head->info == x){
        node *tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    node *p = head;
    node *prev = NULL;
    while(p != NULL && p->info!=x){
        prev = p;
        p = p->next;
    }
    if(p==NULL){
        return;
    }
    prev->next = p->next;
    delete prev;
    return ;
}

void output(node *head){
    node *p = head;
    while(p!=NULL){
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}
int main(){
    node *head;
    init(head);
    insertFirst(head,5);
    insertLast(head,10);
    insertLast(head,20);
    if(search(head,5)){
        cout << "yes" << endl;
    }else {
        cout << "no " << endl;
    }
    del(head,5);
    output(head);
    return 0;
}