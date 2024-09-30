#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void input(int a[],int &n){
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for(int i=0;i<n;i++){
        // cin >> a[i];
        a[i] = rand()%50+1;
    }
}

void output(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void docfile(int a[],int &n){
    ifstream ifs;
    ifs.open("1.txt");
    if(ifs.is_open()){
        ifs >> n;
        for(int i=0;i<n;i++){
            ifs >> a[i];
        }
    } else{
        cout << "Khong doc duoc file!";
    }

}

void insertionSort(int a[],int n){
    for(int i=0;i<n;i++){
        int value = a[i];
        int pos = i-1;
        while(pos>=0 && a[pos]>value){
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = value;
    }
}

void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int pos = i;
        for(int j=i;j<n;j++){
            if(a[j]<a[pos]){
                pos = j;
            }
        }   
        if(pos!=i){
            swap(a[i],a[pos]);
        }
    }
}

void interchangeSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(a[j]<a[i]){
                swap(a[i],a[j]);
            }
        }
    }
}

void bubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }   
}

void bubbleSortRev(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
            }
        }
    }
}

int *merge(int *a ,int n,int *b,int m){
    int *c = new int [n+m];

    int i=0,j=0,cnt=0;

    while(i<n && j <m){
        if(a[i] < b[j]){
            c[cnt++]=a[i++];
        } else {
            c[cnt++]=b[j++];
        }
    }

    while(i<n){
        c[cnt++] = a[i++];
    }
    while (j<m){
        c[cnt++] = b[j++];
    }
    cout << "c: " ;
    output(c,n+m);
    return c; 
}

int *mergeSort(int a[],int n){
    if(n==1){
        return a;
    }
    int mid = n/2;
    int *m1 = new int [mid];
    int *m2 = new int [n-mid];

    for(int i=0;i<mid;i++){
        m1[i] = a[i];
    }
    for(int i =0;i<n-mid;i++){
        m2[i] = a[mid+i];
    }
    m1 = mergeSort(a,mid);
    m2 = mergeSort(m2,n-mid);
    return merge(m1,mid,m2,n-mid);
}

int sequentialSearch(int a[],int n,int x){
    for(int i=0;i<n;i++){
        if(a[i]==x){
            return i;
        }
    }
    return -1;
}

int binarySearch(int a[],int n,int x){
    bubbleSort(a,n);
    int l = 0, r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]==x){
            return mid;
        } 
        if(a[mid]>x){
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return -1;
}

bool kiemtra(int a[],int n){
    int *b =   mergeSort(a,n);\
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
    // delete []b;
}

void menu(){
    cout << "1. Nhap danh sach tu ban phim\n"
        <<"2. Nhap danh sach tu tap tin \n"
        <<"3. Xuat danh sach\n"
        <<"4. Insertion Sort\n"
        <<"5. Selection Sort\n"
        <<"6. Interchange Sort \n"
        <<"7. Bubble Sort \n"
        << "8. Merge Sort \n"
        <<"9. Sequential Sort \n"
        <<"10. Binary Search \n"
        <<"11. Kiem tra mang tang dan \n";
}

int main(){
    int a[MAX];
    int n,choice,x,tmp;
    do{
        system("cls");
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            input(a,n);
            break;
        case 2:
            docfile(a,n);
            break;
        case 3:
            output(a,n);
            break;
        case 4:
            insertionSort(a,n);
            break;
        case 5:
            selectionSort(a,n);
            break;
        case 6:
            interchangeSort(a,n);
            break;
        case 7:
            bubbleSort(a,n);
            break;
        case 8:
            mergeSort(a,n);
            break;
        case 9:
            cout << "Nhap gia tri can tim: ";
            cin >> x;
            tmp = sequentialSearch(a,n,x);
            if(tmp==-1){
                cout << "Khong tim thay \n";
            } else {
                cout << "Co ton tai! \n";
            }
            break;
        case 10:
            cout << "Nhap gia tri can tim: ";
            cin >> x;
            tmp = binarySearch(a,n,x);
            if(tmp==-1){
                cout << "Khong tim thay \n";
            } else {
                cout << "Co ton tai! \n";
            }
            break;
        case 11:
            if(kiemtra(a,n)){
                cout << "Mang duoc sap xep! \n";
            }  else {
                cout << "Mang chua duoc sap xep! \n";
            }
            break;
        default:
            cout << "Chuong trinh khong hop le! \n";
            break;
        }
        system("pause");
    } while (choice!=0);
    return 1;
}