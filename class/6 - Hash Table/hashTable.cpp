#include <bits/stdc++.h>
using namespace std;
#define M 7

struct node {
    int info;
    node *next;
};

void init(node *heads[]){
    for(int i=0;i<M;i++){
        heads[i] = NULL;
    }
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

int hashFunc(int key){
    return key%M;
}

void insert(node *heads[],int x){
    int k = hashFunc(x);
    if(heads[k]==NULL){
        heads[k] = createNode(x);
    } else{
        node *newNode = createNode(x);
        node *p = heads[k];
        if(x<p->info){
            newNode->next = heads[k];
            heads[k] = newNode;
        } else{
            while(p->next!=NULL && p->next->info < x ){
                p=p->next;
            }
            newNode->next = p->next;
            p->next = newNode;
        }
    }
}

node *search(node *heads[],int key){
    int k = hashFunc(key);
    node *p = heads[k];
    while(p!=NULL && p->info != key){
        p = p->next;
    }
    if(p->info == key){
        return p;
    } return NULL;
}

void printHashTable(node* heads[]){
    for(int i=0;i<M;i++){
        if(heads[i]!=NULL){
            cout << "BUCKET " << i << " : " ;
            node *p = heads[i];
            while(p!=NULL){
                cout << p->info << " ";
                p=p->next;
            }
        cout << endl;
        }
    }
}

int main(){
    node *heads[M];
    init(heads);
    insert(heads,14);
    insert(heads,35);
    insert(heads,7);
    insert(heads,28);
    insert(heads,12);
    insert(heads,17);
    insert(heads,23);
    insert(heads,6);
    printHashTable(heads);

    return 1;
}