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

bool sequential_search(int a[],int n,int x){
    for(int i=0;i<n;i++){
        if(a[i]==x){
            return true;
        }
    }
    return false;
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

int main(){
    int a[MAX],n,vt,x ;

    input(a,n);
    sort(a,n);
    output(a,n);
    cout << endl;
    cout << a[binary_search(a,n,4)];

    return 0;
}