#include <bits/stdc++.h>
using namespace std;
#define M 7

struct node {
    int info,next;
};

struct hashTable{
    node h[M];
    int r;
};

int hashFunc(int key){
    return key%M;
}

void init(hashTable &ht){
    for(int i=0;i<M;i++){
        ht.h[i].info = -1;
        ht.h[i].next = -1;
    }
    ht.r = M-1;
}

void insert(hashTable &ht,int x){
    int k = hashFunc(x);
    if(ht.h[k].info == -1){
        ht.h[k].info = x;
    } else{
        //dung do
        ht.h[ht.r].info = x;
        while(ht.h[k].next != -1){
            k = ht.h[k].next;
        }
        ht.h[k].next = ht.r;
    }
    if(ht.r > 0 && ht.h[ht.r].info!=-1){
        ht.r--;
    }
}

void printHashTable(hashTable ht){
    for(int i=0;i<M;i++){
        if(ht.h[i].info!=-1){
            cout << "BUCKET " << i << " : " << ht.h[i].info << " -> " << ht.h[i].next ;
            cout << endl;
        }
    }
}

int search(hashTable ht,int key){
    int k = hashFunc(key);
    while(k!=-1 && ht.h[k].info != key){
        k = ht.h[k].next;
    }
    return k;
}

int main(){
    hashTable ht;
    init(ht);
    insert(ht,7);
    insert(ht,5);
    insert(ht,6);
    insert(ht,14);
    insert(ht,28);
    insert(ht,8);
    insert(ht,2);
    insert(ht,63);
    printHashTable(ht);
    int tmp = search(ht,90);
    if(tmp!= -1){
        cout << ht.h[tmp].info ;
    } else {
        cout << "Khong tim thay";
    }
    return 1;
}