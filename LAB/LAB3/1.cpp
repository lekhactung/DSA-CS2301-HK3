#include <iostream>
using namespace std;
 
struct node {
    int info;
    node *left,*right;
};

void init(node *&root){
    root = NULL;
}

node*  createNode (int x){
    node *p = new node;
    p->info = x;
    p->left = p->right =  NULL;
    return p;
}

void insertNode(node *&root, int x){
    if(root==NULL){
        root = createNode(x);
        return;
    } else if(x<root->info){
        insertNode(root->left,x);
    } else if(x>root->info){
        insertNode(root->right,x);
    } else {
        cout << "Gia tri " << x <<" da ton tai! \n";
        return;
    }
}

int search(node *root,int key){
    if(root==NULL){
        return -1;
    }
    if(root->info==key){
        return root->info;
    }  else if(root->info > key){
        search(root->left,key);
    } else if(root->info < key){
        search(root->right,key);
    }
    return -1;
}

void delNode(node *&root,int key){
    if(root==NULL){
        return;
    }
    if(key<root->info){
        delNode(root->left,key);
    } else if(key>root->info){
        delNode(root->right,key);
    } else {
        if(root->left==NULL){
            node *tmp = root->right;
            delete root;
            root=tmp;
        } else if(root->right==NULL){
            node *tmp = root->left;
            delete root;
            root=tmp;
        } else{
            node *tmp = root->right;
            while(tmp->left!=NULL){
                tmp=tmp->left;
            }
            root->info = tmp->info;
            delNode(root->right,tmp->info);
        }
    }
}

void LNR(node *root){
    if(root!=NULL){
        LNR(root->left);
        cout << root->info << " ";
        LNR(root->right);
    }
}

void RLN(node *root){
    if(root!=NULL){
        RLN(root->right);
        cout << root->info << " ";
        RLN(root->left);
    }
}

void NLR(node *root){
    if(root!=NULL){
        cout << root->info << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

int count(node *root){
    if(root==NULL){
        return 0;
    } 
    return 1+count(root->left)+count(root->right);
}

int main(){
    node *root;
    init(root);
    insertNode(root,20);
    insertNode(root,10);
    insertNode(root,12);
    insertNode(root,5);
    insertNode(root,2);
    insertNode(root,25);
    insertNode(root,19);
    insertNode(root,12);
    insertNode(root,15);

    LNR(root);
    cout << endl;
    delNode(root,10);
    LNR(root);
    cout << endl;
    cout << count(root);
    return 1;
}