#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define MAX 100


struct NTN {
	int ngay, thang, nam;
};

struct SinhVien {
	int MSSV;
	string hoten;
	char ngaysinh[100];
	string quequan;
	double diemTB;
};

struct DSSV {
	int soluong;
	SinhVien sv[MAX];
};

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
	cout << "===================== \n";

} 

void nhapdssv(DSSV &ds) {
	do {
		cout << "Nhap so luong sinh vien: "; cin >> ds.soluong;
		if (ds.soluong <= 0 || ds.soluong > MAX)
			cout << "Nhap lai! \n";
	} while (ds.soluong <= 0 || ds.soluong > MAX);
	for (int i = 0; i < ds.soluong; i++)
		nhap1sv(ds.sv[i]);
}

void xuatdssv(const DSSV ds) {
	for (int i = 0; i < ds.soluong; i++)
		xuat1sv(ds.sv[i]);
}

void docfiledssv(DSSV &ds,string tenFile) {
	ifstream ifs;
	ifs.open(tenFile);
	if (ifs.is_open()) {
		ifs >> ds.soluong;
		ifs.ignore();
		for (int i = 0; i < ds.soluong; i++) {
			ifs >> ds.sv[i].MSSV; ifs.ignore();
			getline(ifs, ds.sv[i].hoten, '#');
			ifs.getline(ds.sv[i].ngaysinh, 11, '#');
			getline(ifs, ds.sv[i].quequan, '#');
			ifs >> ds.sv[i].diemTB;
		}

		ifs.close();
	}
	else {
		cout << "Khong mo duoc file!";
	}
}

int search(DSSV ds, int key) {
	for (int i = 0; i < ds.soluong; i++) {
		if (ds.sv[i].MSSV == key) {
			return i;
		}
	}
	return -1;
}

int search(DSSV ds, string key) {
	for (int i = 0; i < ds.soluong; i++) {
		if (ds.sv[i].hoten == key || ds.sv[i].quequan == key) {
			return i;
		}
	}
	return -1;
}

void swap(SinhVien &sv1, SinhVien &sv2){
	SinhVien tmp;
	tmp = sv1; 
	sv1 = sv2;
	sv2 = tmp;
}

int cmpWithIdDesc(const SinhVien sv1, const SinhVien sv2) {
	return sv1.MSSV > sv2.MSSV ? 1 : (sv1.MSSV < sv2.MSSV) ? -1 : 0;
}

int cmpWithIdAsc(const SinhVien sv1, const SinhVien sv2) {
	return -(sv1.MSSV > sv2.MSSV ? 1 : (sv1.MSSV < sv2.MSSV) ? -1 : 0);
}

int cmpWithNameAsc(const SinhVien sv1, const SinhVien sv2) {
	return -(sv1.hoten > sv2.hoten ? 1 : (sv1.hoten < sv2.hoten) ? -1 : 0);
}

int cmpWithNameDesc(const SinhVien sv1, const SinhVien sv2) {
	return sv1.hoten > sv2.hoten ? 1 : (sv1.hoten < sv2.hoten) ? -1 : 0;
}
void sort(DSSV &ds, int comparator(SinhVien,SinhVien)) {
	for (int i = 0; i < ds.soluong-1; i++) {
		for (int j = i+1; j < ds.soluong; j++) {
			if (comparator(ds.sv[i],ds.sv[j])) {
				swap(ds.sv[i], ds.sv[j]);
			}
		}
	}
}

void xoasv(DSSV &ds, int key) {
	int tmp = search(ds, key);
	for (int i = tmp; i < ds.soluong; i++) {
			ds.sv[i] = ds.sv[i + 1];
	}
	ds.soluong--;
}

void themsv(DSSV &ds) {
	cout << "Nhap thong tin sinh vien can them! \n";
	ds.soluong++;
	nhap1sv(ds.sv[ds.soluong-1]);
}
int main() {
	DSSV ds;
	docfiledssv(ds,"SinhVien.txt");
	xuatdssv(ds);
	sort(ds, cmpWithNameAsc);
	cout << "=========SORT==========";
	xuatdssv(ds);

	system("pause");
	return 0;
}