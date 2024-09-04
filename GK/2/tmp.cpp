#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    int namSinh;
    float diemTB;
};

struct Node {
    SinhVien data;
    Node* next;
    Node(SinhVien sv) : data(sv), next(nullptr) {}
};

class QuanLySinhVien {
private:
    Node* head;

    void themSinhVien(const SinhVien& sv) {
        Node* newNode = new Node(sv);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

public:
    QuanLySinhVien() : head(nullptr) {}

    void docDuLieuTuFile(const string& tenFile) {
        ifstream file(tenFile);
        if (!file) {
            cout << "Không thể mở file!" << endl;
            return;
        }

        SinhVien sv;
        while (file >> sv.maSV >> sv.hoTen >> sv.namSinh >> sv.diemTB) {
            themSinhVien(sv);
        }

        file.close();
        cout << "Đã đọc dữ liệu từ file thành công." << endl;
    }

    void hienThiDanhSach() {
        if (!head) {
            cout << "Danh sách sinh viên trống." << endl;
            return;
        }

        cout << left << setw(10) << "Mã SV" << setw(20) << "Họ Tên" 
             << setw(10) << "Năm Sinh" << setw(10) << "Điểm TB" << endl;
        cout << string(50, '-') << endl;

        Node* current = head;
        while (current) {
            cout << left << setw(10) << current->data.maSV 
                 << setw(20) << current->data.hoTen
                 << setw(10) << current->data.namSinh 
                 << setw(10) << fixed << setprecision(2) << current->data.diemTB << endl;
            current = current->next;
        }
    }

    void timKiemSinhVien(const string& maSV) {
        Node* current = head;
        while (current) {
            if (current->data.maSV == maSV) {
                cout << "Tìm thấy sinh viên:" << endl;
                cout << "Mã SV: " << current->data.maSV << endl;
                cout << "Họ Tên: " << current->data.hoTen << endl;
                cout << "Năm Sinh: " << current->data.namSinh << endl;
                cout << "Điểm TB: " << current->data.diemTB << endl;
                return;
            }
            current = current->next;
        }
        cout << "Không tìm thấy sinh viên với mã " << maSV << endl;
    }

    void ghiDuLieuRaFile(const string& tenFile) {
        ofstream file(tenFile);
        if (!file) {
            cout << "Không thể mở file để ghi!" << endl;
            return;
        }

        Node* current = head;
        while (current) {
            file << current->data.maSV << " " 
                 << current->data.hoTen << " " 
                 << current->data.namSinh << " " 
                 << current->data.diemTB << endl;
            current = current->next;
        }

        file.close();
        cout << "Đã ghi dữ liệu ra file thành công." << endl;
    }

    ~QuanLySinhVien() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    QuanLySinhVien qlsv;
    int luaChon;
    string tenFile = "sinhvien2.txt";

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Đọc dữ liệu từ file" << endl;
        cout << "2. Hiển thị danh sách sinh viên" << endl;
        cout << "3. Tìm kiếm sinh viên" << endl;
        cout << "4. Ghi dữ liệu ra file" << endl;
        cout << "0. Thoát" << endl;
        cout << "Nhập lựa chọn của bạn: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                qlsv.docDuLieuTuFile(tenFile);
                break;
            case 2:
                qlsv.hienThiDanhSach();
                break;
            case 3: {
                string maSV;
                cout << "Nhap ma sv can tim: ";
                cin >> maSV;
                qlsv.timKiemSinhVien(maSV);
                break;
            }
            case 4:
                qlsv.ghiDuLieuRaFile(tenFile);
                break;
            case 0:
                cout << "Cam on" << endl;
                break;
            default:
                cout << "Kh hop le" << endl;
        }
    } while (luaChon != 0);

    return 0;
}