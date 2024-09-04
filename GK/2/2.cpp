#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct SinhVien {
    string hoten,lop;
    // ,mssv,sdt,diemtb; 
    long mssv,sdt;
    float diemtb;
};

struct node{
    SinhVien sv;
    node *next;
};

void init(node *&head){
    head = NULL;
}

node* createNode(SinhVien sv){
    node *p = new node;
    p->sv = sv;
    p->next = NULL;
    return p;
}

void insertNode(node *&head,SinhVien sv){
    node *p = createNode(sv);
    if(head==NULL){
        head = p;
        return;
    } else{
        node *tmp = head;
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = p;
    }
}

void outputHV(SinhVien sv){
    cout << "Ho ten: " <<sv.hoten << endl;
        cout << "MSVV: " <<sv.mssv << endl;
        cout << "Lop: " <<sv.lop << endl;
        cout << "SDT: " <<sv.sdt << endl;
        cout << "Diem tb: " <<sv.diemtb << endl;
        cout << "--------------------------- \n";
}

void output(node *head){
    while(head!=NULL){
        outputHV(head->sv);
        head = head->next;
    }
}

void docFile(node *&head,string tenfile){
    ifstream ifs(tenfile,ios::out);
    if(ifs.is_open()){
        while(true){
            SinhVien sv;
            if (!getline(ifs, sv.hoten, '#')) break;
            if (!(ifs >> sv.mssv)) break; 
            ifs.ignore(1); // Skip the delimiter
            if (!getline(ifs, sv.lop, '#')) break;
            if (!(ifs >> sv.sdt)) break; 
            ifs.ignore(1); // Skip the delimiter
            if (!(ifs >> sv.diemtb)) break; 
            ifs.ignore(1); // Skip the delimiter
            insertNode(head,sv);
            // outputHV(sv);
        }
        cout << "Doc du lieu thanh cong! \n";
        ifs.close();
    } else{
        cout << "Khong mo duoc file! \n";
    }
}

void customizeOutput(node *head, string name,string lop){
    if(head!=NULL){
        node *p = head;
        while(p!=NULL){
            if(p->sv.lop == lop && p->sv.hoten == name){
                outputHV(p->sv);
                return;
            } else {
                p = p->next;
            }
        }
        cout << "RESULT: Khong tim thay sinh vien!\n";
        
    }   
}

void delHV(node *&head, string lop){
    node* p = head;
    node* prev = NULL;

    while (p != NULL) {
        if (p->sv.lop == lop) {
            node* temp = p;
            if (prev == NULL) {
                head = p->next;
            } else {
                prev->next = p->next;
            }
            p = p->next;
            delete temp;
        } else {
            prev = p;
            p = p->next;
        }
    }
}

int main (){
    node *head;
    init(head);
    docFile(head,"sinhvien.txt");
    // customizeOutput(head,"Le Thanh Long","ds23cs01");
    delHV(head,"ds23cs01");
    output(head);
    return 1;
}