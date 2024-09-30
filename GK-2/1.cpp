#include <iostream>
using namespace std;

#define MAX 100000

void input(int a[MAX],int n){
    for(int i=0;i<n;i++){
        a[i] = rand()%50+1;
    }
}

void output(int a[],int n){
    for(int i = 0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int sequentialSearch(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key){
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

void interchangeSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
        output(a,n);
    }
}

void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int pos = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[pos]){
                pos = j;
            }
        }
        if(pos != i){
            swap(a[pos],a[i]);
        }
    }
}

void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        cout << i << ": ";
        int value = a[i];
        int pos = i-1;
        while(pos>=0 && a[pos]>value){
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1] = value;
        output(a,n);
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
void output2(int a[],int l,int r){
    for(int i=l;i<=r;i++){
        cout << a[i] << " " ;
    }
    cout << endl;
}
void quickSort(int a[],int left, int right){
    int pivot = a[(left+right)/2];
    int l = left, r = right;
    do{
        while(a[l]<pivot){
            l++;
        } 
        while(a[r]>pivot){
            r--;
        }
        if(l<=r){
        cout << "r : " << r << " | l : " << l << endl;
            swap(a[r],a[l]);
            output(a,10);
            l++ ; r--;
        }
        // output2(a,left,right);
    } while(l<=r);
    if(l<right){
        quickSort(a,l,right);
    }
    if(left < r){
        quickSort(a,left,r);
    }
}

int binarySearch(int a[],int n, int key){
    interchangeSort(a,n);
    int l = 0, r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]==key){
            return mid;
        }
        if(a[mid]>key){
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return -1;
}

void heapify(int a[], int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && a[left]>a[largest]){
        largest = left;
    }
    if(right<n && a[right]>a[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

void heapSort(int a[],int n){
    for(int i=n/2+1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i = n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int *merge(int *a, int n, int *b,int m){
    int *c = new int[n+m];
    int i=0,j=0,cnt=0;
    while(i<n && j<m){
        if(a[i] < b[i]){
            c[cnt++] = a[i++];
        } else{
            c[cnt++]= b[j++];
        }
    }
    for(int k=i;k<n;k++){
        c[cnt++]=a[k];
    }
    for(int k=j;k<m;k++){
        c[cnt++]=b[k];
    }
    return c;
}

int *mergeSort(int a[],int n){
    if(n==1){
        return a;
    } 
    int mid = n/2;
    int *m1 = new int [mid];
    int *m2 = new int[n-mid];
    for(int i=0;i<mid;i++){
        m1[i] = a[i];
    }
    for(int i =0;i<n-mid;i++){
        m2[i] = a[mid+i];
    }
    m1 = mergeSort(m1,mid);
    m2 = mergeSort(m2,n-mid);
    return merge(m1,mid,m2,n-mid);
}



int main(){
    // int a[MAX];
    int n = 10;
    // input(a,n);
    int a[n] = {42,18,35,1,20,25,29,9,13,15};
    // output(a,n);
    // insertionSort(a,n);
    // output(a,n);
    // heapSort(a,n);
    // int *b = mergeSort(a,n);
    // output(b,n);
    // delete []b;
    quickSort(a,0,n-1);
    return 1;
}