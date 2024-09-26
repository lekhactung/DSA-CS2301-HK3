#include <iostream>
using namespace std;
#define M 99
struct node {
    int key;
    node *next;
};

node *heads[M];

int h(int key){
    return key%M;
}

void init(node *heads[M]){
    for(int i=0;i<M;i++){
        heads[M] = NULL;
    }
}

node *createNode(int key){
    node * p =new  node;
    p->key = key;
    p->next = NULL;
    return p;
}

void insert(node *heads[M],int key){
    int k = h(key);
    if(heads[k]==NULL){
        heads[k]=createNode(key);
    } else {
        node *p = heads[k];
        while(p!=NULL){
            p=p->next;
        }
        p = createNode(key);
    }
}

void Traverse(node *p) // duyệt DSLK
{
    while (p != NULL)
    {
        cout << p->key << ' ';
        p = p->next;
    }
    cout << endl;
}

void TraverseHashTable(node *heads[M])
{
    for (int i = 0; i < M; i++)
    {
        cout << "Bucket " << i << ": ";
        Traverse(heads[i]);
    }
}

int main(){
    node *heads[M];
    init(heads);
    insert(heads,10);
    insert(heads,20);
    insert(heads,30);
    insert(heads,40);
    TraverseHashTable(heads);

    return 1;
}