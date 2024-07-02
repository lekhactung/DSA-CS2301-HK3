#include <iostream>
using namespace std;

struct node {
    int info;
    node *next;
};

struct circlelinkedlist{
    node *head;
    node *tail;
};

void init(circlelinkedlist &cl){
    cl.head = NULL;
    cl.tail = NULL;
}

node *createNode (int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addFirst (circlelinkedlist &cl, int x){
    node *p = createNode(x);
    if(cl.head==NULL){
        cl.head = cl.tail = p;
        cl.tail->next = cl.head;
    }
    else {
        p->next = cl.head;
        cl.head = p;
        cl.tail->next = cl.head;    
    }
}


void output(circlelinkedlist cl){
    if(cl.head!=NULL){
        node *p = cl.head;
        do{
            cout << p->info << " ";
            p = p->next;
        } while(p!=cl.head);
    }
}
int main(){
    circlelinkedlist cl;
    init(cl);
    addFirst(cl,10);
    addFirst(cl,20);
    addFirst(cl,30);
    addFirst(cl,40);
    addFirst(cl,50);
    output(cl);
    return 1;
}