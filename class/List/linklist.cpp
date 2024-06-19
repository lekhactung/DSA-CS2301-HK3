#include <bits/stdc++.h>
using namespace std;

struct Node {
    //Vung thong tin
    int num;
    //Vung lien ket
    Node *next;
    
};
//khoi tao dslk
void init(Node *&head){
    head = NULL;
}

Node* createNode( int x){
    Node *p = new Node;
    p->num = x ;
    p->next = NULL;
    return p;
}

void insert_first(Node *&head,int x){
    Node *p = createNode(x);

    if(head == NULL){
        head = p;
    } else {
        p->next = head;
        head = p;
    }
}

void insertLast(Node *&head,int x){
    Node *p = createNode(x);

    if(head  == NULL){
        head = p;
    } else{
        Node *plast = head;
        while (plast->next!=NULL){
            plast = plast->next;
        }
        plast->next = p;

    }
}

Node* find (Node *head , int key){
    Node *p = head;
    // while(p!=NULL){
    //     if(p->num==key){
    //         return p;
    //     }
    //     p = p->next;
    // }
    // return NULL;
    while(p!=NULL && p->num != key){
        p = p->next;
    }
    return p;
}

void first_delete(Node *&head){
    if(head!=NULL){
        Node *p = head;
        head = head->next;
        p->next = NULL;
        delete p;
    }
}

void last_delete(Node *&head){
    Node *p = head;
    if(head!=NULL){
        Node *plast = head;
        Node *prelast = NULL;
        while(plast ->next != NULL){
            prelast = plast;
            plast = plast->next;
        }
        prelast->next = NULL;
        delete prelast;
        plast = NULL;
    }

}

void printList (Node *head){
    Node *p = head;
    while(p!= NULL){
        cout << p->num <<" ";
        p = p->next;
    }
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("input.txt","w",stdout);

    Node *head ;
    init(head);
    insert_first(head,10);
    insert_first(head,20);
    insertLast(head,30);
    printList(head);
    cout << endl;
    // Node *kq = find(head,10);
    // if(kq!=NULL){
    //     cout << kq->num << endl;;
    // } else{
    //     cout << "Khong tim thay";
    // }

    // first_delete(head);
    last_delete(head);
    printList(head);
    return 0;
}