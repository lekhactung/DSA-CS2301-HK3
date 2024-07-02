#include <bits/stdc++.h>
using namespace std;
#define MAX 100

void input(int a[],int &n){
    do{
        cout << "Nhap so gia tri cua mang: ";
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        if(n<=0 || n >=MAX){
            cout << "So luong khong hop le! Vui long nhap lai \n";
        }
    } while(n<=0 || n >=MAX);
}

void output(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}

void add_index(int a[],int &n,int vt,int x){
    cout << "Nhap vi tri phan tu can them gia tri vua nhap: ";
    cin >> vt;
    if(vt>0 && vt <=n+1){
        for(int i=n;i>=vt;i--){
            a[i]=a[i-1];
        }
        a[vt-1]=x;
        n++;
        cout <<"Da them! \n";
    } else {
        cout <<"Vi tri khong hop le!\n";
    }
}

int sequential_search(int a[],int n,int x){
    for(int i=0;i<n;i++){
        if(a[i]==x){
            return i;
        }
    }
    return -1;
}

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void sort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]<=a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}

int binary_search(int a[],int n,int x){
    sort(a,n);
    int l = 1, r = n;
    while(l<=n){
        int mid = l+r/2;
        if(a[mid]==x){
            return mid;
        }
        if(a[mid]<x){
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return -1;
}

void del_arr(int a[],int &n,int x){
    if(sequential_search(a,n,x)!=-1){
        for(int i=sequential_search(a,n,x);i<n;i++){
            a[i] = a[i+1];
        }
        n--;
        cout << "Da xoa!";
    } else {
        cout << "Gia tri khong ton tai trong mang";
    }
}

int *gopmang(int a[],int b[],int n,int m){
    int *c = new int [n+m];
    int index =0; 
    for(int i=0;i<n;i++){
        c[index++] = a[i];
    }
    for(int i=0;i<m;i++){
        c[index++] = b[i];
    }
    sort(c,n+m);
    return c;
}

void menu(){
    cout << "1. Them mot phan tu vao danh sach \n"
        <<"2. Xuat cac phan tu trong danh sach \n"
        <<"3. Tim mot phan tu trong danh sach bang tim kiem tuan tu \n"
        <<"4. Tim mot phan tu trong danh sach bang tim kiem nhi phan \n"
        <<"5. Tim mot phan tu trong danh sach, xoa phan tu neu tim duoc \n"
        <<"6. Nhap mang thu 2  \n"
        <<"7. Gop 2 danh sach dac da co thu tu thanh 1 danh sach co thu tu \n";
}

int main(){
    int a[MAX],n,vt,x;
    int b[MAX],m;
    int choice;
    bool flag = false;
    input(a,n);
    int *c;
    do{
        
        do{
            system("cls");
            menu();
            cout << "Nhap chuong trinh : ";
            cin >> choice;
            if(choice !=0 && choice !=1 &&choice !=2 &&choice !=3 &&choice !=4 &&choice !=5 &&choice !=6 && choice !=7) {
                cout <<"Vui long nhap lai!" << endl;
            }
        } while( choice!=0 && choice !=1 &&choice !=2 &&choice !=3 &&choice !=4 &&choice !=5 &&choice !=6 && choice !=7);

        switch (choice)
        {
        case 1:
            cout <<"Nhap gia tri can them: ";
            cin >> x;
            add_index(a,n,vt,x);
            break;
        
        case 2:
            cout << "Cac gia tri cua mang thu 1  : \n ";
            output(a,n);
            break;
        
        case 3:
            cout << "Nhap gia tri can tim: ";cin >> x;
            if(sequential_search(a,n,x)!=-1){
                cout << "Phan tu co trong danh sach! \n";
            } else{
                cout <<"Phan tu khong co trong danh sach! \n";
            }
            break;
        case 4: 
            cout << "Nhap gia tri can tim : "; cin >> x;
            if(binary_search(a,n,x)!=-1){
                cout << "Phan tu co trong danh sach! \n";
            } else{
                cout <<"Phan tu khong co trong danh sach! \n";
            }
            break;
        case 5:
            cout <<"Nhap phan tu can tim va xoa: "; cin >> x;
            del_arr(a,n,x);
            break;
        case 6:
            input(b,m);
            flag = true;
            break;
        case 7:
            if(flag){
                c = new int(n+m);
                c = gopmang(a,b,n,m);
                output(c,n+m);
            } else{
                cout <<"Chua khai bao mang thu 2! \n";
            }
            break;
        default:
            break;
        }
        system("pause");
    } while(choice !=0 );
    return 0;
}