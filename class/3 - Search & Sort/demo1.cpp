#include <iostream>
using namespace std;

void swap (int &a,int &b){
    int  tmp = a;
    a = b;
    b = tmp;
}

void quickSort(int a[],int left,int right){
    int l = left, r = right;
    int pivot = a[(left+right)/2]; 
    while(l<=r){
        while(a[l]<pivot){
            l++;
        }
        while(a[r]>pivot){
            r--;
        }
        if(l<=r){
            swap(a[l],a[r]);
            l++;
            r--;
        }
    }
    if(left<r){
        quickSort(a,left,r);
    }
    if(l<right){
        quickSort(a,l,right);
    }
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
    quickSort(a,0,n-1);
    output(a,n);
    return 1;
}