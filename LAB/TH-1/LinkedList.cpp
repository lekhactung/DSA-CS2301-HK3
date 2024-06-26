#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define MAX 100
struct SinhVien {
	int MSSV;
	string hoten;
	char ngaysinh[100];
	string quequan;
	double diemTB;
};

struct node {
	SinhVien sv;
	node *next;
};

node *createNode (SinhVien x){
	node *p = new node;
	p->sv = x;
	p->next = NULL;
	return p;
}

void init(node *&head) {
	head = NULL;
}


void nhap1sv(SinhVien &sv) {
	cout << "Nhap MSSV: "; cin >> sv.MSSV; cin.ignore();
	cout << "Nhap ho va ten: "; getline(cin, sv.hoten);
	cout << "Nhap ngay sinh: "; cin >> sv.ngaysinh; cin.ignore();
	cout << "Nhap que quan: "; getline(cin, sv.quequan);
	cout << "Nhap diem TB: "; cin >> sv.diemTB;
}

void xuat1sv(const SinhVien sv) {
	cout << "===================== \n";
	cout << "MSSV : " << sv.MSSV << endl;
	cout << "Ho va ten : " << sv.hoten << endl;
	cout << "Ngay sinh : " << sv.ngaysinh << endl;
	cout << "Que quan : " << sv.quequan << endl;
	cout << "Diem TB : " << sv.diemTB << endl;

}

void insertFirst(node *&head, SinhVien sv) {
	node *p = createNode(sv);
	if (head == NULL) {
		head = p;
	}
	else {
		p->next = head;
		head = p;
	}
}

void insertLast(node *&head, SinhVien sv) {
	node *p = createNode(sv);
	if (head == NULL) {
		head = p;
	}
	else {
		node *plast = head;
		while (plast->next != NULL) {
			plast = plast->next;
		}
		plast->next = p;
	}
}


void docfiledssv(node *&head,string tenFile) {
	ifstream ifs;
	ifs.open(tenFile);
	if (ifs.is_open()) {
		SinhVien sv;
		int n, i=0;
		ifs >> n;
		ifs.ignore();
		while(i<n){
			ifs >> sv.MSSV; ifs.ignore();
			getline(ifs,sv.hoten,'#');
			ifs.get(sv.ngaysinh,11);ifs.ignore();
			getline(ifs,sv.quequan,'#');
			ifs >> sv.diemTB; ifs.ignore();
			insertLast(head,sv);
			i++;
		}

		ifs.close();
	}
	else {
		cout << "Khong mo duoc file!";
	}
}

node* search(node *head, int key) {
	node *p = head;
	if (head == NULL) {
		return NULL;
	}
	while (p != NULL && p->sv.MSSV != key) {
		p = p->next;
	}
	if (p == NULL) {
		return NULL;
	}
	return p;
}

node* search(node *head, string key) {
	node *p = head;
	if (head == NULL) {
		return NULL;
	}
	while (p != NULL && p->sv.hoten != key && p->sv.quequan != key) {
		p = p->next;
	}
	if (p == NULL) {
		return NULL;
	}
	return p;
}
void output(node *head) {
	while (head != NULL) {
		xuat1sv(head->sv);
		head = head->next;
	}
}

int main() {
	node *head;
	SinhVien sv;
	init(head);
	// int chon = 1;
	// while (chon != 0) {
	// 	nhap1sv(sv);
	// 	insertLast(head, sv);
	// 	cout << "Tiep tuc : 1 /// Dung lai : 0 \n ::";
	// 	cin >> chon;
	// }
	docfiledssv(head,"SinhVien.txt");
	// output(head);
	// cout << "======tim kiem======= \n";
	
	node *tmp = search(head,"Pham Thi Dao");
	if(tmp!=NULL){
		xuat1sv(tmp->sv);
	} else {
		cout << "no";
	}
	return 0;
}