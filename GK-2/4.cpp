#include <iostream>
using namespace std;

struct node{
    int info ;
    node *left,*right;
};

void init(node *&root){
    root  = NULL;
}

node *createNode(int x){
    node *p = new node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(node *&root,int x){
    if(root==NULL){
        root = createNode(x);
    } else{
        node *p = root;
        while(p!=NULL){
            if(p->info > x){
                if(p->left==NULL){
                    p->left = createNode(x);
                    break;
                }
                p = p->left;
            } else if(p->info < x){
                if(p->right== NULL){
                    p->right = createNode(x);
                    break;
                }
                p=p->right;
            } else{
                return;
            }
        }
    }
}

void delNode(node *&root,int key){
    if(root!=NULL){
        node *p = root;
        node *parent = NULL;
        while(p!=NULL && p->info !=key){
            parent = p;
            if(p->info > key){
                p = p->left;
            } else {
                p = p->right;
            }
        }
        if(p!=NULL){
            if(p->left!=NULL && p->right!=NULL){
                parent = p;
                node *r = root->right;
                while(r->left != NULL){
                    parent = r;
                    r = r->left;
                }
                p->info = r->info ;
                p = r;
            }
            node *t;
            if(p->right == NULL){
                t = p->left;
            } else if(p->left ==NULL){
                t = p->right;
            }

            if(parent->info > p->info ){
                parent->left = t;
            } else {
                parent->right = t;
            }
            delete p;
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
int main(){
    node *root;
    init(root);
    insertNode(root,10);
    insertNode(root,20);
    insertNode(root,5);
    insertNode(root,50);
    insertNode(root,30);
    insertNode(root,90);
    LNR(root);
    cout << endl;
    delNode(root,10);
    LNR(root);
    return 1;
}