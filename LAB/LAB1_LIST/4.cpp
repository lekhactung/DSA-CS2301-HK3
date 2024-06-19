#include <bits/stdc++.h>
using namespace std;

struct Node{
    int info;
    Node *link;
};

void init(Node *&head){
    head = NULL;
}

Node* createNode (int x){
    Node *p = new Node;
    p->info = x;
    p->link = NULL;
    return p;
}

void insertLast(Node *&head,int x){
    Node *p = createNode(x);
    if(head == NULL){
        head = p;
    } else {
        Node *plast = head;
        while(plast->link != NULL){
            plast = plast->link;
        }
        plast->link = p;
    }
    
}

void insertFirst(Node *&head,int x){
    Node *p = createNode(x);
    if(head == NULL){
        head = p;
    } else {
        p->link = head;
        head = p;
    }
    
}

void delFirst(Node *&head){
    if(head!=NULL){
        Node *p = head;
        head = head->link;
        p->link = NULL;
        delete p;
    }
}

void delLast(Node *&head){
    Node *p = head;
    if(head!=NULL){
        Node *plast = head;
        Node *previousLast = NULL;
        while(plast->link != NULL){
            previousLast = plast;
            plast = plast->link;
        }
        previousLast->link = NULL;
        delete previousLast;
        plast = NULL;
    }
}


void output(Node *head){
    Node *p = head;
    while(p!=NULL){
        cout << p->info << " ";
        p = p->link;
    }
}

// Node* search(Node *head,int x){
//     Node *p = head;
//     while(p!=NULL && p->info != x){
//         p = p->link;
//     }
//     return p;
// }

bool search( Node *head, int x){
    Node *p = head;
    while(p->link!=NULL){
        if(p->info == x){
            return true;
        }
        p = p->link;
    }
    return false;
}

void deleteNode(Node *head,int x){
    if(head==NULL){
        cout <<"DS rong!";
    } else{
        Node *p = head;
        Node *prev = NULL;
        while(p!=NULL && p->info != x){
            prev = p;
            p = p->link;
        }
        if(prev == NULL){
            return;
        } 
        
        prev->link = p->link;
        delete p;
    }
}

int main(){

    Node *head;
    init(head);
    insertLast(head,10);
    insertLast(head,20);
    insertLast(head,30);
    insertFirst(head,5);
    output(head);
    // Node *kq = search(head,50);
    cout << endl << "////////////////////////"<< endl;
    // if(kq!=NULL){
    //     cout << kq->info;
    // } else{
    //     cout << "Khong tim thay!";
    // }
    if(search(head,10)){
        deleteNode(head,10);
    } else{
        cout << "no";
    }
    output(head);
    delFirst(head);
    delLast(head);
    cout << endl << "////////////////////////"<< endl;
    output(head);

    
    return 0;
}