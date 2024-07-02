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

void delFirst(doubleLinkedList &dl){
    node *p = dl.head;
    if(p!=NULL){
        dl.head = dl.head->next;
        dl.head->prev = NULL;
        p->next = NULL;
        delete p;
    }
}

void delLast(doubleLinkedList &dl){
    node  *p = dl.tail;
    if(p!=NULL){
        dl.tail = dl.tail->prev;
        dl.tail->next = NULL;
        p->prev = NULL;
        delete p;
    }
}

// void delKey(doubleLinkedList &dl, int key){
//     node *p = dl.head;
//     while(p!=NULL && p->info != key){
//         p = p->next;
//     } 
//     if(p==NULL){
//         return;
//     }
//     node *tmp = p;
//     p->prev->next = p->next;
//     p->next = p->next->next;
//     tmp->prev = NULL;
//     tmp->next =NULL;

//     delete tmp;
// }

node *search (doubleLinkedList dl,int key){
    node *p = dl.head;
    while(p!=NULL){
        if(p->info == key){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void delKey(doubleLinkedList &dl,int key){
    node *tmp = search(dl,key);
    if(tmp == NULL){
        cout << "Phan tu khong ton tai!";
        return ;
    }
    if(tmp->prev !=NULL){
        tmp->prev->next = tmp ->next;
    } else{
        dl.head = tmp->next;
    }
    if(tmp->next!=NULL){
        tmp->next->prev = tmp->prev;
    }
    delete tmp;
}

// node *findCloset(doubleLinkedList dl,int key){
//     node *p = dl.head;
//     node *closet = nullptr;
//     while(p!=NULL){
//         if(p->info >= key){
//             if(closet!=NULL || p->info < closet->info)
//                 closet = p;
//         }
//         p=p->next;
//     }
//     return closet;
// }

// void append(doubleLinkedList &dl,int x){
//     node *p = createNode(x);
    
// }

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
void destroyNode(doubleLinkedList &dl){
    node *p = dl.head;
    while(p!=NULL){
        dl.head = dl.head->next;
        p->next = NULL;
        p->prev = NULL;
        delete p;

        p=dl.head;
    }
}

void menu(){
    cout << "1. Xuat cac phan tu trong danh sach \n"
        <<"2. Them phan tu vao dau danh sach \n"
        << "3. Them phan tu vao cuoi danh sach \n"
        <<"4. Xoa phan tu dau danh sach \n"
        <<"5. Xoa phan tu cuoi danh sach \n"
        <<"6. Tim phan tu trong danh sach va xoa phan tu do neu tim duoc \n"
        <<"7. Tim phan tu gan voi gia tri nhap vao va them mot phan tu truoc phan tu duoc tim thay \n";

}
int main(){
    doubleLinkedList dl;
    init(dl);
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
            output(dl);
            break;
        
        case 2:
            cout << "Nhap phan tu can them vao dau danh sach: ";
            cin >> x;
            addFirst(dl,x);
            break;
        case 3:
            cout << "Nhap gia tri can them vao cuoi danh sach: ";
            cin >> x;
            addLast(dl,x);
            break;
        case 4:
            delFirst(dl);
            cout << "Da xoa! \n";
            break;
        case 5:
            delLast(dl);
            cout << "Da xoa! \n";
            break;
        case 6:
            cout << "Nhap phan tu can tim va xoa :";
            cin >> x;
            delKey(dl,x);
            break;
        case 7:
            cout << "Em khong biet lam a T_T \n";
            break;
        default:
            break;
        }
        system("pause");
    } while(choice!=0);
    
    return 1;
}