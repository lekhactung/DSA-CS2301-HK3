#include <iostream>
#include <fstream>
using namespace std;

struct node {
    int info;
    node *next;
};

void init(node *&head){
    head = NULL;
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void swap(node *&a,node *&b){
    node *tmp = a;
    a = b;
    b = tmp;
}

void pushBack(node *&head,int x){
    node * p = createNode(x);
    if(head == NULL){
        head = p;
    } else {
        node *plast = head;
        while(plast->next!=NULL){
            plast = plast->next;
        }
        plast ->next = p;
        p->next = NULL;
    }
}

void input(node *&head , int x){
    cin >> x;
    pushBack(head,x);
}

void docfile(node *&head){
    ifstream ifs;
    ifs.open("2.txt");
    int n,x;
    if(ifs.is_open()) {
        ifs >> n ;
        for(int i=0;i<n;i++){
            ifs >> x;
            pushBack(head,x);
        }
    } else {
        cout << "Khong mo duoc file!";
    }

}

void insertionSort(node *head){
    int value;
    node *p = head;
    node *j = head;
    for( node *i = head; i!=NULL ;i=i->next){
        value = i->info;
        while(j!=NULL){
            if( j->info > value){
                j = j->next;
            }
        }
        
    }
}

void output(node *head){
    while(head!=NULL){
        cout << head->info << " ";
        head = head ->next;
    }
        cout << endl;
}

void destroyNode(node *&head){
    while(head!=NULL){
        node *tmp = head;
        head = head->next;
        tmp->next = NULL;
        delete tmp;
    }
}

int main(){
    node *head;
    init(head);
    docfile(head);
    output(head);
    selectionSort(&head);
    output(head);
    destroyNode(head);

    return 1;
}