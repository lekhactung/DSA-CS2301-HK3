#include <iostream>
using namespace std;

struct node {
    int info;
    node *prev;
    node *next;
};

struct doubleLinkedList {
    node *head;
    node *tail;
};

void init(doubleLinkedList &list){
    list.head = NULL;
    list.tail = NULL;
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insertFirst(doubleLinkedList &list, int x){
    node *p = createNode(x);
    if(list.head == NULL){
        list.head = list.tail = p;
    } else{
        p->next = list.head;
        list.head->prev = p;
        list.head = p;
    }
}

void insertLast(doubleLinkedList &list,int x){
    node *p = createNode(x);

    if(list.head ==NULL){
        list.head = list.tail = p;
    } else{
        p->prev = list.tail;
        list.tail->next = p;
        list.tail = p;
    }
}

node* search(doubleLinkedList list,int key){
    node *p = list.head;
    while(p!=NULL && p->info != key){
        p = p->next;
    }
    return p;
}

void insertAfter(doubleLinkedList &list,int key,int x){
    node *q = search(list,key);
    if(q!=NULL){
        node *p = createNode(x);
        if(q->next == NULL){
            insertLast(list,x);
        }else{
            q->next->prev = p;
            p->next = q->next;
            p->prev = q;
            q->next = p;
        }
    }

}

void delFirst(doubleLinkedList &list){
    if(list.head!=NULL){
        node *p = list.head;
        if(list.head->next ==NULL){
            list.head->prev = list.head->next = NULL;
        }else {
            list.head = list.head->next;
            list.head->prev = NULL;
            p->next = NULL;
        }
        delete p;
    }
}

void delLast(doubleLinkedList &list){
    if(list.head!=NULL){
        node *p = list.tail;
        if(list.head->next == NULL){
            list.head->prev = list.head->next = NULL;
        } else{
            list.tail = list.tail->prev;
            list.tail->next =NULL;
            p->prev = NULL;
        }
        delete p;
    }
}


void output(doubleLinkedList list){
    while(list.head!=NULL){
        cout << list.head->info << " ";
        list.head = list.head->next;
    }
}

void re_output(doubleLinkedList list){
    while(list.tail!=NULL){
        cout << list.tail->info << " ";
        list.tail = list.tail->prev;
    }
}
int main(){
    doubleLinkedList list;
    init(list);

    insertFirst(list,10);
    // insertFirst(list,20);
    // insertLast(list,30);
    // insertLast(list,40);
    // output(list);
    // delFirst(list);
    // delLast(list);
    // cout << endl;
    // output(list);
    // cout << "\n======TIM KIEM======== \n";
    // // node *kq = search(list,50);
    // // if(kq!=NULL){
    // //     cout << kq->info << endl;
    // // } else {
    // //     cout << "Khong tim thay";
    // // }
    // cout << endl;
    // insertAfter(list,10,99);
    output(list);

    return 0;
}