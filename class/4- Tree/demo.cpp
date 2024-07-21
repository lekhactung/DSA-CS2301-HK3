#include <iostream>
using namespace std;

struct node {
    int info;
    node *left,*right;
};

void init(node *&root){
    root = NULL;
}

node *createNode (int x){
    node *p = new  node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(node *&root, int x){
    if(root==NULL){
        root = createNode(x);
    } else{
        node *p = root;
        while (p!=NULL && p->info != x){
            if(p->info > x){
                if(p->left==NULL){
                    p->left = createNode(x);
                    break;
                } 
                p = p->left;
            } else{
                if(p->right==NULL){
                    p->right = createNode(x);
                    break;
                }
                p=p->right;
            }
        }
    }
}

node *seach(node *root,int key){
    node *p = root;
    while(p!=NULL && p->info != key){
        if(p->info > key){
            p = p->left;
        }
        else{
            p = p->right;
        }
    }
    return p;
}

void delNode(node *&root,int key){
    if(root!=NULL){
        node *p = root;
        node *parent = NULL;
        //tim node can xoa
        while(p!=NULL && p->info !=key){
            parent = p;
            if(p->info > key){
                p = p->left;
            } else{
                p = p->right;
            }
        }
        if(p!=NULL){
            if(p->left !=NULL && p->right !=NULL){
                parent = p;
                node *r = p->right;
                while(r->left!=NULL){
                    parent = r;
                    r = r->left;
                }
                p->info = r->info;
                p = r;
            }
            node *t;
            if(p->right==NULL){
                t = p->left;
            } else if(p->left==NULL){
                t = p->right;
            }

            if(parent->info > p->info){
                parent->left = t;
            }else {
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

int main(){
    node *root;
    init(root);
    insertNode(root,40);
    insertNode(root,60);
    insertNode(root,20);
    insertNode(root,10);
    insertNode(root,15);
    insertNode(root,45);
    insertNode(root,7);




    // node *tmp = seach(root,15);
    // if(tmp!=NULL){
    //     cout << tmp->info;
    // } else{
    //     cout << "Khong tim thay! \n";
    // }

    LNR(root);
    cout << endl;
    delNode(root,40);
    LNR(root);

    // NLR(root);
    // RLN(root);
    return 1;
    //15 20 8 40 12 90 
    //40 60 20 10 15 45
}