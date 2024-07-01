#include <iostream>

using namespace std;

struct node{
    int info;
    node *next;
};

struct circularLinkedList{
    node*head;
};

void init(circularLinkedList cl){
    cl.head = NULL;
}


node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void insertFirst(circularLinkedList &cl,int x){
    node *p = createNode(x);
    if(cl.head == NULL){
        cl.head = p;
        cl.head->next = p;
    } else{

    }
}

void output(circularLinkedList cl){
    if(cl.head !=NULL){
        node *p = cl.head;
        do{
            cout << p->info;
            p=p->next;
        } while(p!=cl.head);
    }
}



int main(){
    circularLinkedList cl;
    init(cl);
    insertFirst(cl,10);
    output(cl);
    return 0;
}