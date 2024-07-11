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

void output(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[MAX];
    // int n = sizeof(a)/sizeof(a[0]);
    int n;
    // input(a,n);
    docfile(a,n);
    output(a,n);
    // insertionSort(a,n);
    // selectionSort(a,n);
    // interchangeSort(a,n);
    // bubbleSort(a,n);
    bubbleSortRev(a,n);
    output(a,n);

    return 1;
}