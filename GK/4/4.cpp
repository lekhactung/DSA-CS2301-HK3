#include <iostream>
using namespace std;

struct node{
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

void insert(node *&root,int x){
    if(root == NULL){
        root = createNode(x);
    } else{
        node *p = root;
        while(p!=NULL){
            if(p->info > x){
                if(p->left ==NULL){
                    p->left = createNode(x);
                    break;
                }
                p=p->left;
            } else if(p->info <x){
                if(p->right == NULL){
                    p->right = createNode(x);
                    break;
                }
                p = p->right;
            } else{
                return;
            }
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

void NLR(node *root){
    if(root!=NULL){
        cout << root->info << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void delNode(node *&root,int key){
    if(root!=NULL){
        node *p = root;
        node *parent = NULL;
        while(p!=NULL && p->info != key){
            parent = p;
            if(p->info > key){
                p = p->left;
            } else{
                p = p->right;
            }
        }

        if(p!=NULL){
            if(p->left != NULL && p->right !=NULL){
                node *r = p->right;
                while(r->left!=NULL){
                    parent = r;
                    r = r->left;
                }
                p->info = r->info;
                p = r;
            }

            node *t ;
            if(p->right == NULL){
                t = p->left;
            } else if(p->left==NULL){
                t = p->right;
            }

            if(parent->info > p->info){
                parent->left = t;
            } else{
                parent->right = t;
            }
            delete p;
        }
    }
}

int main(){
    node *root;
    init(root);
    insert(root,10);
    insert(root,20);
    insert(root,5);
    insert(root,12);
    insert(root,13);
    insert(root,28);
    // NLR(root);
    LNR(root);
    delNode(root,10);
    cout << endl;
    LNR(root);
    return 1;
}