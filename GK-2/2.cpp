#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct SinhVien{
    string hoten,lop;
    long mssv,sdt;
    float diemtb;
};

struct node{
    SinhVien sv;
    node *next;
};

void init(node *&root){
    root = NULL;
}

node *createNode(SinhVien sv){
    node *p = new node;
    p->sv = sv;
    p->next = NULL;
    return p;
}

void insertSV(SinhVien sv){
    getline(cin,sv.hoten);
    cin >> sv.mssv ; cin.ignore();
    getline(cin,sv.lop);
    cin >> sv.sdt; cin.ignore();
    cin >> sv.diemtb;
}

void addSV(node *&root,SinhVien sv){
    if(root==NULL){
        root = createNode(sv);
    }
}

void outputsv(SinhVien sv){
    cout << "Ho va ten : " << sv.hoten << endl; 
    cout << "Lop : " << sv.lop << endl;
    cout << "MSSV : " << sv.mssv << endl;
    cout << "SDT : " <<sv.sdt << endl;
    cout << "Diem tb : " << sv.diemtb << endl;
}

void output(const node *root){
    if(root!=NULL){
        while(root!=NULL){
            outputsv(root->sv);
            root = root->next;
        }
    }
}
int main(){
    node *root;
    init(root);

    return 1;
}