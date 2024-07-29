#include <iostream>
using namespace std;


//Cau truc cay AVL
struct node {
    int key;
    node *left,*right;
    int height;
};

void init(node *&root){
    root = NULL;
}

node *createNode(int x){
    node *p = new node;
    p->key = x;
    p->left = p->right = NULL;
    p->height = 1;
    return p;
}

int getHeight(node *root){
    if(root==NULL){
        return 0;
    } 
    return root->height;
}

void rightRotate(node *&root){
    node *x = root->left;
    root->left = x->right;
    x->right = root;
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    x->height = 1+max(getHeight(x->left),getHeight(x->right));
    root = x;
}

void leftRotate(node *&root){
    node *x = root->right;
    root->right = x->left;
    x->left = root;
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    x->height = 1+max(getHeight(x->left),getHeight(x->right));
    root = x;
}

void insertNode(node *&root,int x){
    if(root==NULL){
        root = createNode(x);
    } 
    else {
        if(root->key > x){
            insertNode(root->left,x);
        } else if(root->key < x){
            insertNode(root->right,x);
        } else{
            return;
        }
        root->height = 1+max(getHeight(root->left),getHeight(root->right));

        int val = getHeight(root->left) - getHeight(root->right);
        if(val>1 && root->left->key >x){
            //lech trai trai
            rightRotate(root);
        } else if(val<-1 && root->right->key <x){
            //lech phai phai
            leftRotate(root);
        } else if(val>1 &&root->left->key < x){
            rightRotate(root);
            leftRotate(root);
            //lech trai phai
        } else if(val<-1 && root->right->key > x){
            //lech phai trai
        }
    }
}

void LNR(node *root){
    if(root!=NULL){
        LNR(root->left);
        cout << root->key << "(" << root->height <<")  ";
        LNR(root->right);
    }
}


void NLR(node *root){
    if(root!=NULL){
        cout << root->key << "(" << root->height <<")  ";
        LNR(root->left);
        LNR(root->right);
    }
}

int main(){
    node *root;
    init(root);
    insertNode(root,40);
    insertNode(root,20);
    insertNode(root,60);
    insertNode(root,15);
    insertNode(root,25);
    insertNode(root,30);
    // insertNode(root,25);

    LNR(root);
    cout << endl;
    // NLR(root);

    return 1;
}