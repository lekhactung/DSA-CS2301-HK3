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

}

int sequenceSearch(int a[],int n,int key){

}

void output(int a[],int n){
    int i=0;
    while(i<n){
        cout << a[i++] << " ";
    }
    cout << endl;
}

int main(){
    int n =10;
    int a[n];
    for(int i =0 ;i<n;i++){
        a[i] = rand()%10+1;
    }
    output(a,n);
    sort(a,n);
    output(a,n);
    return 1;
}