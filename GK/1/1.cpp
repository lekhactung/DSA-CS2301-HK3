#include <iostream>
#include <time.h>
using namespace std;
#define MAX 100

void input(int a[],int n){
    for(int i=0;i<n;i++){
        // cin >> a[i];
        a[i] = rand()%100+1;
    }
}

void output(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


int senquentialSearch(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}

void swap(int &a,int &b){
    int tmp = a;
    a =  b;
    b = tmp;
}

void sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}

int binarySearch(int a[],int n, int key){
    sort(a,n);
    int left = 0;
    int right = n-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(a[mid]==key){
            return mid;
        } 
        if(a[mid]<key){
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}

void addLast(int a[],int &n,int value){
    n+=1;
    a[n-1] = value;
}

void delLast(int a[],int &n){
    n--;
}

void delIndex(int a[],int &n,int index){
    if (index >= 0 && index < n) {
        for (int i = index; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;
    } else {
        cout << "Vi tri khong hop le!" << endl;
    }
}

void addIndex(int a[],int &n,int index, int value){
    if (index >= 0 && index <= n) {
        for(int i=n;i>index;i--){
            a[i]=a[i-1];
        }
        a[index] = value;
        n++; 
    } else {
        cout << "Vi tri khong hop le hoac mang da day!" << endl;
    }
}

int findMax(int a[],int n){
    int max = a[0];   
    int index; 
    for(int i=0;i<n;i++){
        if(a[i]>=max){
            max = a[i];
            index = i;
        }
    }
    return index;
}

int findSencondMin(int a[],int n){
    int max = findMax(a,n),secondMax = a[0];
    int index;
    for(int i=0;i<n;i++){
        if(a[i]<a[max] && a[i]>secondMax){
            secondMax = a[i];
            index = i;
        }
    }
    return index;
}   

void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int pos = i;
        for(int j = i+1; j< n ;j++){
            if(a[j]<a[pos]){
                pos = j;
            }
        }
        if(pos!=i){
            swap(a[i],a[pos]);
        }
    }
}

void insertionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int value = a[i];
        int pos = i-1;
        while(pos>=0 && a[pos]>value){
            a[pos]=a[pos-1];
            pos--;
        }
        a[pos+1] = value;
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

void interchangeSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}

void quickSort(int a[],int left,int right){
    int pivot = a[(left+right)/2];
    int l = left, r = right;
    do{
        while(a[l]>pivot){
            l++;
        }
        while(a[r]<pivot){
            r--;
        }
        if(l<=r){
            swap(a[l],a[r]);
            l++;
            r--;
        }
    }while (l<=r);
    if(l<right){
        quickSort(a,l,right);
    }
    if(left < r){
        quickSort(a,left,r);
    }
}   

void heapify(int a[],int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < n && a[left] < a[largest]){
        largest = left;
    } 
    if(right < n && a[right] < a[largest]){
        largest = right;
    }
    if(largest != i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void heapsort(int a[],int n){
    for(int i = n/2+1;i>=0;i--){
        heapify(a,n,i);
    }
    for (int i = n-1;i>=0;i--){
        swap(a[i],a[0]);
        heapify(a,i,0);
    }
}
int main(){
    // srand(time(NULL));
    int a[MAX];
    int n = 10;
    input(a,n);
    output(a,n);
    cout << "//////////" << endl;
    // cout << n << endl;
    heapsort(a,n);
    output(a,n);
    return 1;
}