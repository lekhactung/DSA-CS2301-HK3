#include <iostream>
using namespace std;
struct node{
    int info;
    node *left,*right;
    int height;
};

void init(node *&root){
    root = NULL;
}

int max(const int a, const int b){
    return a > b ? a : b;
}

int getHeight(node *root){
    if(root!=NULL){
        return root->height;
    }
    return 0;
}

int getBalance(node *root){
    if(root!=NULL){
        return getHeight(root->left) - getHeight(root->right);
    }
    return 0;
}

void updateHeight(node *&root){
    if(root!=NULL){
        root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    }
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->left = p->right = NULL;
    p->height = 1;
    return p;
}

void rightRotate(node *&root){
    node *x = root->left;
    root->left = x->right;
    x->right = root;

    updateHeight(root);
    updateHeight(x);
    root = x;
}

void leftRotate(node *&root){
    node *x = root->right;
    root->right = x->left;
    x->left = root;

    updateHeight(root);
    updateHeight(x);
    root = x;
}

void insertNode(node *&root,int x){
    if(root==NULL){ 
        root = createNode(x);
    } else if(x>root->info){
        insertNode(root->right,x);
    } else if(x<root->info){
        insertNode(root->left,x);
    } else{
        return;
    }

    updateHeight(root);

    int val = getBalance(root);
    if(val > 1 && x < root->left->info){
        rightRotate(root);
    } else if(val > 1 && x > root->left->info){
        leftRotate(root->left);
        rightRotate(root);
    } else if( val< -1 && x > root->right->info){
        leftRotate(root);
    } else if(val<-1 && x < root->right->info){
        rightRotate(root->right);
        leftRotate(root);
    }
}


void LNR(node *root){
    if(root!=NULL){
        LNR(root->left);
        cout << root->info << "(" << root->height << ") ";
        LNR(root->right);
    }
}

int main(){
    node *root;
    init(root);
    insertNode(root,10);
    insertNode(root,20);
    insertNode(root,30);
    insertNode(root,40);
    insertNode(root,5);
    insertNode(root,1);
    LNR(root);
    return 1;
}