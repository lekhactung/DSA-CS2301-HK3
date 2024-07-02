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

bool search(Node *head, int x){
    Node *p = head;
    while(p!=NULL){
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
        <<"3. Them phan tu vao dau danh sach \n"
        <<"4. Xoa phan tu dau danh sach \n"
        << "5. Them phan tu vao cuoi danh sach \n"
        <<"6. Xoa phan tu cuoi danh sach \n"
        <<"7. Tim phan tu trong danh sach va xoa phan tu do neu tim duoc \n";
}

int main(){

    Node *head;
    init(head);
    int choice,x;
    do{
        do{
            system("cls");
            menu();
            cout << "Nhap chuong trinh : ";
            cin >> choice;
            if(choice !=0 && choice !=1 &&choice !=2 &&choice !=3 &&choice !=4 &&choice !=5 &&choice !=6 &&choice !=7) {
                cout <<"Vui long nhap lai!" << endl;
            }
        } while( choice!=0 && choice !=1 &&choice !=2 &&choice !=3 &&choice !=4 &&choice !=5 &&choice !=6 &&choice !=7);


        switch (choice)
        {
        case 1:
            output(head);
            break;
        case 2:
            cout << "Nhap phan tu can tim: ";
            cin >> x;
            if(search(head,x)){
                cout << "Phan tu co trong danh sach!" << endl;
            }else {
                cout << "Phan tu khong co trong danh sach! " << endl;
            }
            break;
        case 3:
            cout << "Nhap phan tu can them vao dau danh sach: ";
            cin >> x;
            insertFirst(head,x);
            break;
        case 4:
            delFirst(head);
            cout <<"Da xoa!" << endl;
            break;
        case 5:
            cout << "Nhap gia tri can them vao cuoi danh sach: ";
            cin >> x;
            insertLast(head,x);
            break;
        case 6:
            delLast(head);
            cout << "Da xoa!" << endl;
            break;
        case 7:
            cout << "Nhap phan tu can tim va xoa :";
            cin >> x;
            if(search(head,x)){
                deleteNode(head,x);
                cout << "Da xoa!" << endl;
            } else {
                cout << "Phan tu khong co trong danh sach!";
            }
            break;
        
        default:
            break;
        }
        system("pause");
    } while(choice!=0);
    
    return 0;
}