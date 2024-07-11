#include <iostream>
using namespace std;

void output(int a[],int n){
    int i = 0;
    while(i<n){
        cout << a[i++] << " ";
    } 
    cout << endl;
}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void selection(int a[],int n){
    for(int i=0;i<n-1;i++){
        int pos = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[pos]){
                pos = j; 
            }
        }
        if(pos!=i){
            swap(a[pos],a[i]);
        }
        output(a,n);
    }
}

void insertion(int a[],int n){
    for(int i=0;i<n;i++){
        int value = a[i];
        int pos = i-1;
        while(pos>=0 && a[pos]>value){
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1]=value;  
    }
}

void interchange(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
                cout << i << " : ";
                output(a,n);
            }
        }
    }
}

void bubble(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                swap(a[j+1],a[j]);
            }
        }
    }
}

void bubble2(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
            }
        }
    }
}

/*void merge(int a[],int l, int m,int r){
    int i=0,j=0,k;
    int L[]={3,27,38,43};
    int R[]={9,10,82,100};
    
    int n1=sizeof(L)/sizeof(L[0]);
    int n2=sizeof(R)/sizeof(R[0]);

    int b[n1+n2];

    for(k=0;i<n1 & j<n2;k++){
        if(L[i]<R[j]){
            b[k] = L[i++];
        } else{
            b[l] = R[j++];
        }
    }

    while(i<n1){
        b[k++] = L[i++];
    }
    while(j<n2){
        b[k++] = R[j++];
    }

    output(b,n1+n2);
}*/

int *merge(int *a,int n,int *b,int m){
    int *c = new int[n+m];

    int i=0,j=0,cnt=0;

    while(i<n && j<m){
        if(a[i]<b[j]){
            c[cnt++]=a[i++];
        } else{
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

int *mergeSort(int a[],int n){
    if(n==1){
        return a;
    }
    
    int mid = n/2;
    int *m1 = new int[mid];
    int *m2 = new int[n-mid];

    for(int i = 0;i<mid;i++){
        m1[i] = a[i];
    }
    for(int i = 0;i<n-mid;i++){
        m2[i] = a[mid+i];
    }
    output(m1,mid);
    output(m2,n-mid);
    m1 = mergeSort(m1,mid);
    m2 = mergeSort(m2,n-mid);
    return merge(m1,mid,m2,n-mid);
}

int main(){
    int a[]={65,73,88,12,10,93,27};
    int n = sizeof(a)/sizeof(a[0]);
    // output(a,n);
    // // selection(a,n);
    // // insertion(a,n);
    // interchange(a,n);
    // // bubble(a,n);
    // // bubble2(a,n);
    output(a,n);

    int *b = mergeSort(a,n);
    output(b,n);
    delete []b;

    return 1;
}