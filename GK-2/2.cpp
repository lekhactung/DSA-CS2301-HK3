#include <iostream>
#include <fstream>
#include <string>
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

void init(node *&head){
    head = NULL;
}

node *createNode(SinhVien sv){
    node *p = new node;
    p->sv = sv;
    p->next = NULL;
    return p;
}

void insertSV(SinhVien &sv){
    cout << "Nhap ho ten sinh vien: ";
    // cin.ignore();
    getline(cin,sv.hoten);
    cout << "Nhap MSSV : ";
    cin >> sv.mssv ; cin.ignore();
    cout << "Nhap lop sinh vien: ";
    getline(cin,sv.lop);
    cout << "Nhap SDT sinh vien : ";
    cin >> sv.sdt; cin.ignore();
    cout << "Nhap diem tb: ";
    cin >> sv.diemtb; cin.ignore();
}

void addSV(node *&head,SinhVien sv){
    if(head==NULL){
        head = createNode(sv);
        return;
    } else {
        node *p = head;
        while (p->next!=NULL){
            p=p->next;
        }
        p->next = createNode(sv);
    }
}

void docfile(node *&head, string tenfile){
    ifstream ifs(tenfile,ios::out);
    if(ifs.is_open()){
        while(!ifs.eof()){
            SinhVien sv;
            getline(ifs,sv.hoten,'#');
            ifs >> sv.mssv ; ifs.ignore();
            getline(ifs,sv.lop,'#');
            ifs >> sv.sdt ; ifs.ignore();
            ifs >> sv.diemtb; ifs.ignore();
            addSV(head,sv);
        }
    } else{
        cout << "Khong mo duoc file";
    }
    ifs.close();
}

void outputsv(SinhVien sv){
    cout << "Ho va ten : " << sv.hoten << endl; 
    cout << "Lop : " << sv.lop << endl;
    cout << "MSSV : " << sv.mssv << endl;
    cout << "SDT : " <<sv.sdt << endl;
    cout << "Diem tb : " << sv.diemtb << endl;
}

void output(const node *head){
    if(head!=NULL){
        while(head!=NULL){
            cout << "--------- \n";
            outputsv(head->sv);
            head = head->next;
        }
    }
}

node *search(node *head, string ten,string lop){
    if(head!=NULL){
        node *p = head;
        while(p!=NULL && p->sv.lop != lop && p->sv.hoten!=ten){
            p = p->next;
        }
        if(p!=NULL){
            return p;
        }
    }
    return NULL;
}

void delClass(node *&head, string lop){
    if(head!=NULL){
        node *p = head;
        node *prev=NULL;
        while(p!=NULL){
            if(p->sv.lop == lop){
                node *tmp =p;
                if(prev == NULL){
                    head = p->next;
                } else{
                    prev->next = p->next;
                }
                p = p->next;
                delete tmp;
            } else{
                prev = p;
                p = p->next;
            }
        }
    }
}

void swapNode(node *&a, node *&b){
    
}

void sortDsc(node *&head){
    if(head!=NULL){
        node *p = head;
        while(p!=NULL){
            
        }
    }
}

int main(){
    node *head;
    init(head);
    // SinhVien sv1,sv2,sv3;
    // sv1.hoten = "Tung";
    // sv1.lop = "cs2301";
    // sv1.mssv =123;
    // sv1.sdt=91273891;
    // sv1.diemtb = 5;

    // sv2.hoten = "Huy";
    // sv2.lop = "cs2302";
    // sv2.mssv =234;
    // sv2.sdt=127242;
    // sv2.diemtb = 4.5;

    // sv3.hoten = "Ha";
    // sv3.lop = "it2301";
    // sv3.mssv =456;
    // sv3.sdt=123623;
    // sv3.diemtb = 5.9;
    // addSV(head,sv1);
    // addSV(head,sv2);
    // addSV(head,sv3);
    // output(head);
     
    docfile(head,"sinhvien.txt");
    // output(head);
    // node *tmp = search(head,"Nguyen Thi Phuong","dh23cs01");
    // outputsv(tmp->sv);
    delClass(head,"ds23cs01");
    output(head);
    return 1;
}