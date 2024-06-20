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
    cout << endl;
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

int count(Node *head){
    int cnt=0;
    while(head!=NULL){
        ++cnt;
        head=head->link;
    }
    return cnt;
}

void deleteNode(Node *&head,int x){
    if(head==NULL){
        return;
    } 
    if(head->info == x){
        Node  *tmp = head;
        head = head->link;
        delete tmp;
        return;
    }
    Node *p = head;
    Node *prev = NULL;
    while(p!=NULL && p->info!=x){
        prev = p;
        p = p->link;
    }
    if(p==NULL){
        return;
    }
    prev->link = p->link;
    delete prev;    
    return;
}

void menu(){
    cout << "1. Xuat cac phan tu trong danh sach \n"
        <<"2. Tim phan tu trong danh sach \n"
        <<"3.Them phan tu vao dau danh sach \n"
        <<"4.Xoa phan tu dau danh sach \n"
        << "5.Them phan tu vao cuoi danh sach \n"
        <<"6.Xoa phan tu cuoi danh sach \n"
        <<"7.Tim phan tu trong danh sach va xoa phan tu do neu tim duoc \n";
}

int main(){

    Node *head;
    init(head);
    int choice,x;
    insertFirst(head,10);
    insertFirst(head,20);
    insertFirst(head,30);
    insertFirst(head,40);
    insertFirst(head,50);
    insertLast(head,5);
    insertLast(head,99);
    insertLast(head,87);
    insertLast(head,100);
    insertLast(head,123);
    output(head);
    // cout << count(head);
    deleteNode(head,50);

    cout << endl;
    output(head);
    deleteNode(head,10);

    cout << endl;
    output(head);
    deleteNode(head,123);

    cout << endl;
    output(head);
    return 0;
}