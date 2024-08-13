#include <iostream>
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

int hashFunc(int x){
    return x%M;
}

void insertNode(node *heads[],int x){
    int k = hashFunc(x);
    if(heads[k]==NULL){
        heads[k] = createNode(x);
    } else {
        node *p = heads[k];
        node *newNode = createNode(x);
        while(p->next!=NULL && p->next->info < x){
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
}

node *searchNode(node *heads[],int key){
    int k = hashFunc(key);
    if(heads[k]!=NULL){
        node *p = heads[k];
        while(p!=NULL && p->info != key){
            p = p->next;
        }
        return p;
    }
    return nullptr;
}

void delNode(node *heads[],int key){
    int k = hashFunc(key);
    if(heads[k]!=NULL){
        node *p = heads[k];
        if(heads[k]->info == key){
            heads[k]=heads[k]->next;
            p->next = NULL;
            delete p;
            return;
        }
        while(p->next!=NULL && p->next->info !=key){
            p=p->next;
        }
        node *tmp = p->next;
        p->next = tmp->next;
        tmp->next = NULL;
        delete tmp;
    }
}

void destroy(node *heads[]){
    for(int i =0;i<M;i++){
        while(heads[i]!=NULL){
            node *p = heads[i]; 
            heads[i] = heads[i]->next;
            delete p;
        }
    }
}

void printHashTable(node *heads[]){
    for(int i=0;i<M;i++){
        node *p = heads[i];
        if(p!=NULL){
            cout << "BUCKET " << i << " : ";
            while(p!=NULL){
                cout << p->info << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
}

void printReq(node *heads[],int bucket){
    if(heads[bucket]!=NULL){
        node *p = heads[bucket];
        cout << "BUCKET " << bucket << " : ";
            while(p!=NULL){
                cout << p->info << " ";
                p = p->next;
            }
    }
}

int main(){
    node *heads[M];
    init(heads);
    insertNode(heads,10);
    insertNode(heads,15);
    insertNode(heads,7);
    insertNode(heads,4);
    insertNode(heads,20);
    insertNode(heads,100);
    insertNode(heads,34);
    insertNode(heads,63);
    insertNode(heads,23);
    insertNode(heads,75);
    insertNode(heads,32);
    insertNode(heads,72);

    printHashTable(heads);
    // // printReq(heads,2);
    // delNode(heads,15);
    cout << "/////////////////" << endl;
    // // printReq(heads,2);
    destroy(heads);
    printHashTable(heads);
    // cout << "//////SEARCH /////////" << endl;
    // node *tmp = searchNode(heads,11);
    // if(tmp!=NULL){
    //     cout << "Ton tai";
    // } else {
    //     cout << "No";
    // }



    return 1;
}