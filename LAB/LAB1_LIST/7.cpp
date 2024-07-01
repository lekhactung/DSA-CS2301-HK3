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

void addFirst(circlelinkedlist &cl,int x){
    node *p = createNode(x);
    if(cl.head == NULL){
        cl.head = cl.tail = p;
        p->next = cl.head;
    } else {
        p->next = cl.head;
        cl.head = p;
        cl.tail->next = cl.head;
    }
}


void addLast(circlelinkedlist &cl,int x){
    node *p = createNode(x);
    if(cl.head == NULL){
        cl.head = cl.tail = p;
        p->next = cl.head;
    } else {
        cl.tail->next = p;
        cl.tail = p;
        cl.tail->next = cl.head;
    }
}

void delFirst(circlelinkedlist &cl){
   if(cl.head->next!=cl.head){
        node *p = cl.head;
        cl.head = cl.head->next;
        p->next = NULL;
        cl.tail->next = cl.head;
        delete p;
    } else{
        delete cl.head;
        cl.head = nullptr;
    }   
}

void delLast(circlelinkedlist &cl){
    if(cl.head->next!=cl.head){
        node *p = cl.tail;
        node *plast = cl.head;
        while(plast->next != cl.tail){
            plast = plast->next;
        }
        plast->next = cl.head;
        cl.tail = plast;
        p->next= NULL;
        delete p;
    }else{
        delete cl.head;
        cl.head = nullptr;
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
    cout << endl;
}

node *search(circlelinkedlist cl,int key){
    node *p = cl.head;
    do{
        if(p->info==key){
            return p;
        }
        p=p->next;
    } while (p!=cl.head);
    return nullptr;
}

void delKey(circlelinkedlist &cl,int key){
    node *tmp = search(cl,key);
    if(tmp == NULL){
        cout << "Phan tu khong ton tai! ";
        return;
    } 
    if(tmp->next == cl.head){
        delLast(cl);
    } else if(tmp == cl.head){
        delFirst(cl);
    } else{
        node *prev = cl.head;
        while(prev->next!=tmp){
            prev=prev->next;
        }
        prev->next=tmp->next;
        tmp->next=NULL;
        delete tmp;
    }

}

void menu(){
    cout << "1. Xuat cac phan tu trong danh sach \n"
        <<"2. Them phan tu vao dau danh sach \n"
        << "3. Them phan tu vao cuoi danh sach \n"
        <<"4. Xoa phan tu dau danh sach \n"
        <<"5. Xoa phan tu cuoi danh sach \n"
        <<"6. Tim phan tu trong danh sach va xoa phan tu do neu tim duoc \n";
}
int main(){
    circlelinkedlist cl;
    init(cl);
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
            output(cl);
            break;
        
        case 2:
            cout << "Nhap phan tu can them vao dau danh sach: ";
            cin >> x;
            addFirst(cl,x);
            break;
        case 3:
            cout << "Nhap gia tri can them vao cuoi danh sach: ";
            cin >> x;
            addLast(cl,x);
            break;
        case 4:
            delFirst(cl);
            cout << "Da xoa! \n";
            break;
        case 5:
            delLast(cl);
            cout << "Da xoa! \n";
            break;
        case 6:
            cout << "Nhap phan tu can tim va xoa :";
            cin >> x;
            delKey(cl,x);
            break;
        default:
            break;
        }
        system("pause");
    } while(choice!=0);
    
    
    return 1;
}