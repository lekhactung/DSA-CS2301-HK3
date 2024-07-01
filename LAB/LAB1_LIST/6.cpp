#include <iostream>
using namespace std;

struct node {
    int info;
    node *next;
    node *prev;
};

struct doubleLinkedList{
    node *head;
    node *tail;
};

void init(doubleLinkedList &dl){
    dl.head = NULL;
    dl.tail = NULL;
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void addFirst (doubleLinkedList &dl,int x){
    node *p = createNode(x);
    if(dl.head==NULL){
        dl.head = dl.tail = p;
    } else {
        p->next = dl.head;
        dl.head->prev = p;
        dl.head =p;
    }
}

void addLast (doubleLinkedList &dl,int x){
    node *p = createNode(x);
    if(dl.head == NULL){
        dl.head = dl.tail = p;
    } else {
        p->prev = dl.tail;
        dl.tail->next = p;
        dl.tail = p;
    }
}

void output(doubleLinkedList dl){
    while(dl.head!=NULL){
        cout << dl.head->info << " ";
        dl.head = dl.head->next;
    }
    cout << endl;
}

void output2(doubleLinkedList dl){
    while(dl.tail!=NULL){
        cout << dl.tail->info << " ";
        dl.tail = dl.tail->prev;
    }
    cout << endl;
}

int main(){
    doubleLinkedList dl;
    init(dl);
    addFirst(dl,50);
    addFirst(dl,10);
    addLast(dl,100);
    addLast(dl,199);
    
    output(dl);
    return 1;
}