#include <iostream>

using namespace std;
void input(int a[],int &n){
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
}

void output(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
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

int *gopmang(int a[],int b[],int n,int m){
    int *c = new int [n+m];
    int index =0; 
    for(int i=0;i<n;i++){
        c[index++] = a[i];
    }
    for(int i=0;i<m;i++){
        c[index++] = b[i];
    }
    sort(c,n+m);
    return c;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n =5 , m =5;
    int a[n],b[m];
    int *c = new int [n+m];
    input(a,n);
    input(b,m);
    c = gopmang(a,b,n,m);
    output(a,n);
    output(b,m);
    cout << endl;
    output(c,n+m);
    return 0;
}