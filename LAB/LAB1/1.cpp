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

int search(int a[],int n,int &x){
    for(int i=0;i<n;i++){
        if(a[i]==x){
            return i;
        }
    }
    return -1;
}

void add(int a[],int &n,int x){
    n++;
    a[n-1]=x;
}

void del(int a[],int &n){
    n--;
}

void del_index(int a[],int &n,int vt){
    if(vt>0 && vt <=MAX){
        for(int i=vt-1;i<=n;i++){
            a[i]=a[i+1];
        }
        n--;
    } else {
        cout <<"Vi tri khong hop le!";
    }
}

void add_index(int a[],int &n,int vt,int x){
    cout << "Nhap vi tri phan tu can them gia tri vua nhap: ";
    cin >> vt;
    if(vt>0 && vt <=MAX){
        for(int i=n;i>=vt;i--){
            a[i]=a[i-1];
        }
        a[vt-1]=x;
        n++;
    } else {
        cout <<"Vi tri khong hop le!";
    }
}

bool del_if_find(int a[],int &n,int x){
    if(search(a,n,x)!=-1){
        del_index(a,n,search(a,n,x)+1);
        return true;
    } else {
        return false;
    }
}
void menu(){
    cout << "1. Nhap danh sach \n"
        <<"2. Xuat danh sach \n"
        << "3. Tim mot phan tu trong danh sach \n"
        << "4. Them phan tu vao cuoi danh sach \n"
        <<"5. Xoa phan tu cuoi danh sach \n"
        << "6. Xoa phan tu tai vi tri i \n"
        << "7. Them phan tu tai vi tri i \n"
        << "8. Tim phan tu trong danh sach, neu tim thay -> xoa phan tu \n";

}
int main(){ 
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int a[MAX],n;
    int choice,x,vt;

    do{
        do{
            system("cls");
            menu();
            cout << "Nhap chuong trinh : " ;
            cin >> choice;
            if(choice !=0 &&choice !=1 &&choice !=2 &&choice !=3 &&choice !=4 &&choice !=5 &&choice !=6 &&choice !=7 &&choice !=8){
                cout << "Vui long nhap lai!  \n";
            }
        } while(choice !=0 &&choice !=1 &&choice !=2 &&choice !=3 &&choice !=4 &&choice !=5 &&choice !=6 &&choice !=7 &&choice !=8 );

        switch (choice)
        {
        case 1:
            input(a,n);
            break;
        
        case 2:
            output(a,n);
            break;
        
        case 3:
            cout << "Nhap gia tri can tim : ";
            cin >> x;
            if(search(a,n,x)!=-1){
                cout << "Gia tri co trong danh sach!";
            } else {
                cout <<"Gia tri khong co trong danh sach!";
            }
            break;
        
        case 4:
            cout << "Nhap gia tri can them vao cuoi danh sach : ";
            cin >> x;
            add(a,n,x);
            cout << "Da them!";
            break;
        
        case 5:
            del(a,n);
            cout <<"Da xoa!";
            break;
        
        case 6: 
            cout << "Nhap vi tri phan tu can xoa: ";
            cin >> vt;
            del_index(a,n,vt);
            cout << "Da xoa!";
            break;
        
        case 7:
            cout << "Nhap gia tri can them : ";
            cin >> x;
            add_index(a,n,vt,x);
            cout << "Da them!";
            break;
        
        case 8:
            cout << "Nhap phan tu can tim : ";
            cin >> x;
            if(del_if_find(a,n,x)){
                cout << "Da tim thay, da xoa!";
            } else{
                cout << "Khong tim thay!";
            }

            break;
        
        default:
            break;
        }
        cout << endl;
        system("pause");
    } while(choice !=0);

    return 0;
}