#include <iostream>
using namespace std;

struct node {
    int info;
    node *left,*right;
};

void init(node *&root){
    root = NULL;
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(node *&root,int x){
    if(root == NULL ){
        root = createNode(x);
    } else {
        node *p = root;
        while(true){
            if(p->info > x){
                if(p->left == NULL){
                    p->left = createNode(x);
                    break;
                }
                p=p->left;
            } 
            if(p->info<x) {
                if(p->right == NULL){
                    p->right = createNode(x);
                    break;
                }
                p = p->right;
            }
            if(p->info == x){
                break;
            }
        }
    }
}

void delNode(node *&root, const int key){
    if(root == NULL){
        return ;
    } 
    node *p = root;
    node *parent = NULL;
    while(p!=NULL && p->info != key){
        parent = p;
        if(p->info > key){
            p=p->left;
        } else{
            p=p->right;
        }
    }
    if(p->left == NULL && p->right == NULL){
        if(parent->info > p->info ){
            parent->left = NULL;
        } else{
            parent->right = NULL;
        }
        delete  p;
    } else{
        
    }
}

void LNR(node *root){
    if(root!=NULL){
        LNR(root->left);
        cout << root->info << " ";
        LNR(root->right);
    }
}

int main(){
    node *root;
    init(root);
    insertNode(root,40);
    insertNode(root,60);
    insertNode(root,20);
    insertNode(root,10);
    insertNode(root,15);
    insertNode(root,45);
    LNR(root);
    delNode(root,45);
    cout << endl;
    LNR(root);
    return 1;
}