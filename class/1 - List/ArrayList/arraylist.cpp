#include <bits/stdc++.h>
using namespace std;

void output(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}
int search(int a[],int n,int x){
    int i=0;
    while((i<n )&&( a[i]!=x)){
        i++;
    }
    if(i==n){
        return -1;
    } 
    return i;
}

void del(int a[],int &n,int x){
    for(int i=x-1;i<=n;i++){
        a[i]=a[i+1];
    }
    n--;
}

void insert(int a[],int &n, const int vt,const int x){
    n++;
    for(int i=n-1;i>=vt-1;i--){
        a[i+1]=a[i];
    }
    a[vt-1]=x;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    // cout << a[search(a,n,30)] << endl;
    // del(a,n,2);
    insert(a,n,2,100);
    output(a,n);
    // output(a,n);
}