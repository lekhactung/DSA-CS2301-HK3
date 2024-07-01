#include <iostream>
#include <string>
using namespace std;

struct sinhvien{
    int id;
    string name;
};

ostream &operator << (ostream &out, const sinhvien &sv){
    cout << "MSSV  : " << sv.id << endl;
    cout << "Ho ten: " << sv.name << endl;
    
    return out;
}

template <typename T>
struct node {
    T info;
    node<T> *next;
};

template <typename T>
void init(node<T> *&head){
    head = NULL;
}

template <typename T>
node<T> *createNode(T x){
    node<T> *p = new node<T>;
    p->info = x;
    p->next = NULL;
    return p;
}

template <typename T>
void insertFirst(node<T> *&head,T x){
    node<T> *p = createNode(x);
    if(head==NULL){
        head = p;
    } else {
        p->next = head;
        head=p;
    }
}

template <typename T>
void output(node<T> *head){
    while(head!=NULL){
        cout << head->info << " ";
        head = head->next;
    }
}

template <typename T>
void destroyNode(node<T> *&head){
    node<T> *p = head;
    while(p!=NULL){
        head = head->next;
        p->next = NULL;
        delete p;

        p= head;
    }
}


int main(){

    node<int> *head;
    init(head);
    // insertFirst(head,10);
    // insertFirst(head,9);
    // insertFirst(head,8);
    // insertFirst(head,7);
    // insertFirst(head,6);

    sinhvien sv1;
    sv1.id = 10005;
    sv1.name = "Le Khac Tung";
    sinhvien sv2;
    sv2.id = 20005;
    sv2.name = "Tung Le Khac";
    // insertFirst(head,sv1);
    // insertFirst(head,sv2);

    output(head);
    destroyNode(head);
    return 1;
}