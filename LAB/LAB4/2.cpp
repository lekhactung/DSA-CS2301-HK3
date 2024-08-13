#include <iostream>
using namespace std;
#define M 7 
struct node{
    int info,next;
};

struct hashTable{
    node h[M];
    int r;
};

int hashFunc(int x){
    return x%M;
}

void init(hashTable &ht){
    for(int i=0;i<M;i++){
        ht.h[i].info = -1;
        ht.h[i].next = -1;
    }
    ht.r = M-1;
}

void insertNode(hashTable &ht,int x){
    int k = hashFunc(x);
    if(ht.h[k].info == -1){
        ht.h[k].info = x;
    } else {
        ht.h[ht.r].info = x;
        while(ht.h[k].next != -1){
            k = ht.h[k].next;
        }
        ht.h[k].next = ht.r;
        if(ht.r > 0 && ht.h[ht.r].info!= -1){
            ht.r--;
        }
    }
}

int search (hashTable ht,int key){
    int k = hashFunc(key);
    while(k!=-1 && ht.h[k].info != key){
        k = ht.h[k].next;
    }
    return k;
}

int count (hashTable ht){
    int cnt =0 ;
    for(int i=0;i<M;i++){
        if(ht.h[i].info != -1){
            cnt ++ ;
        }
    }
    return cnt;
}

void delNode(hashTable &ht, int key){
    
}

void printHashTable(hashTable ht){
    for(int i=0;i<M;i++){
        if(ht.h[i].info!=-1){
            cout << "BUCKET " << i << " : " << ht.h[i].info << " -> " << ht.h[i].next ;
            cout << endl;
        }
    }
}

int main(){
    hashTable ht;
    init(ht);
    insertNode(ht,7);
    // insertNode(ht,5);
    // insertNode(ht,6);
    insertNode(ht,14);
    insertNode(ht,28);
    // insertNode(ht,8);
    // insertNode(ht,2);
    insertNode(ht,63);
    insertNode(ht,70);
    printHashTable(ht);
    cout << count(ht);
    return 1;
}