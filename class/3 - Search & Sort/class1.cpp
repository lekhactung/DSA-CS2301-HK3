#include <iostream> 
using namespace std;


void swap(int &a,int &b){
    int tmp = a;
    a =  b;
    b = tmp;
}

void sort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}

int binarySearch(int a[],int n,int key){
    sort(a,n);
    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = l+r/2;
        if(a[mid]==key){
            return mid;
        } 
        if(a[mid]>key){
            r = mid-1;
        } 
        else {
            l = mid+1;
        }
    }

    return -1;
}

int sequentialSearch(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}

void output(int a[],int n){
    int i=0;
    while(i<n){
        cout << a[i++] << " ";
    }
    cout << endl;
}

int main(){
    int a[]={9,4,5,2,3,6};
    int n = sizeof(a) / sizeof(a[0]);
    int index=binarySearch(a,n,3);
    // cout << index;
    if(index!=-1){
        cout << a[index]; 
    } else{
        cout << "Khong tim thay!";
    }
    return 1;
}