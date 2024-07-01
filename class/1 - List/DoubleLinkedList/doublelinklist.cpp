#include <iostream>
using namespace std;

struct node{
    int info;
    node *prev;
    node *next;
};

struct doublelinkedlist{
    node *head;
    node *tail;
};

void init(doublelinkedlist &list){
    list.head = NULL;
    list.tail = NULL;
}

node* createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insertFirst(doublelinkedlist &list, int x){
    node *p = createNode(x);

    if(list.head == NULL){
        list.head = list.tail = p;
    } else {
        p->next = list.head;
        list.head->prev = p;
        list.head = p;
    }
}

void insertLast(doublelinkedlist &list,int x){
    node *p = createNode(x);
    
    if(list.head == NULL){
        list.head = list.tail = p;
    } else {
        p->prev = list.tail;
        list.tail->next = p;
        list.tail = p;
    }
}

void duyet(const doublelinkedlist list){
    node *p = list.head;
    while(p!=NULL){
        cout << p->info << " ";
        p = p->next;
    }
}

void duyet2(const doublelinkedlist list){
    node *p = list.tail;
    while(p!=NULL){
        cout << p->info << " ";
        p = p->prev;
    }
}
int main(){
    doublelinkedlist ls;
    init(ls);
    insertFirst(ls,10);
    insertFirst(ls,20);
    insertFirst(ls,30);
    insertLast(ls,5);
    duyet(ls);

    return 0;
}