#include <iostream> 
using namespace std;


void swap(int &a,int &b){
    int tmp = a;
    a =  b;
    b = tmp;
}

int sequentialSearch (int a[],int n,int key){
    for(int i = 0;i<n;i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}

int binarySearch(int a[],int n, int key){
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

void selectionSort(int a[],int n){
    int min;
    for(int i =0;i<n-1;i++){
        min = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min!=i){
            swap(a[min],a[i]);
        }
    }
}

void bubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j+1],a[j]);
            }
        }
    }
    
}

void insertionSort (int a[],int n){
    for(int i=1;i<n;i++){
        int x = a[i];
        int pos = i-1;
        while(pos >=0 && a[pos]>x){
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1] = x;
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
    int pivot = a[(left+right) /2];
    int l = left, r = right;
    do{
        while(a[l] < pivot){
            l++;  
        } 
        while(a[r]> pivot){
            r--;
        }
        if(l<=r){
            swap(a[l],a[r]);
            l++;
            r--;
        }
    } while(l<=r);
    if(left < r){
        quickSort(a,left,r);
    } 
    if(l < right ){
        quickSort(a,l,right);
    }

}

int *merge (int *a, int n, int *b, int m){
    int *c = new int[n+m];
    
    int i=0,j=0,cnt=0;

    while( i<n && j<m){
        if(a[i]<b[j]){
            c[cnt++]=a[i++];
        } else {
            c[cnt++]=b[j++];
        }
    }
    for(int k=i;k<n;k++){
        c[cnt++] = a[k];
    }
    for(int k=j;k<m;k++){
        c[cnt++] = b[k];
    }
    return c;
}

int *mergeSort (int a[],int n){
    if(n==1){
        return a;
    }

    int mid = n/2;
    int *m1 = new int [mid];
    int *m2 = new int [n-mid];
    for(int i =0;i<mid;i++){
        m1[i] = a[i];
    }
    for(int i=0;i<n-mid;i++){
        m2[i]=a[mid+i];
    }
    m1 = mergeSort(m1,mid);
    m2 = mergeSort(m2,n-mid);

    return merge(m1,mid,m2,n-mid);
}

void output(int a[],int n){
    int i=0;
    while(i<n){
        cout << a[i++] << " ";
    }
    cout << endl;
}

int main(){
    int a[]={2,5,1,3,6,10,7,1,15,100,20,99,1};
    int n = sizeof(a)/sizeof(a[0]);
    // int b[]={2,5,6};
    // int c[]={3,8,9,10,15};
    // int *d = mergeSort(a,n);
    // for(int i=0;i<8;i++){
    //     cout << d[i] << " ";
    // }
    // delete []d;
    output(a,n);
    // // selectionSort(a,n);
    // // bubbleSort(a,n);
    // // insertionSort(a,n);
    // interchangeSort(a,n);
    // quickSort(a,0,n-1);
    
    int *b = mergeSort(a,n);
    output(b,n);
    delete []b;
    return 1;
}