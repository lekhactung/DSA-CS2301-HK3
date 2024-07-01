#include <iostream>
#include <string.h>
using namespace std;

struct HocVien{
    string msv,ten;
    int namsinh;
};

struct node{
    HocVien sv;
    node *next;
};

void init(node *&head){
    head->next = NULL;
}

void outputHV(HocVien hv){
    cout <<"MSV: " << hv.msv << endl;
    cout << "Ho ten: " <<hv.ten << endl;
    cout << "Nam sinh: " <<hv.namsinh << endl;
}

node *createNode (HocVien x){
    node *p = new node;
    p->sv = x;
    p->next = NULL;
    return p;
}

void addFirst(node *&head,HocVien x){
    node *p = createNode(x);
    if(head == NULL ){
        head = p;
    } else {
        p->next = head;
        head = p;
    }
}

void duyet(const node *head){
    while(head!=NULL){
        outputHV(head->sv);
        head = head->next;
    }
}

int main(){
    node *head;
    HocVien h1;
    h1.msv = "2351010238";
    h1.ten = "Tung";
    h1.namsinh = 2005;
    HocVien h2;
    h2.msv = "2351010238";
    h2.ten = "Tien";
    h2.namsinh = 2003;
    
    addFirst(head,h1);
    addFirst(head,h2);

    duyet(head);

    return 0;
}