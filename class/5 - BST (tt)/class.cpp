#include <bits/stdc++.h>
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

void insertNode(node *&root, int x){
    if(root == NULL){
        root = createNode(x);
    } else{
        if(x<root->info){
            insertNode(root->left,x);
        } else if(x>root->info){
            insertNode(root->right,x);
        } else {
            cout << "Node " << x <<" da ton tai!\n";
            return ;
        }
    }
}

node *search(node *root, int key){
    if(root==NULL){
        return nullptr;
    }
    if(root->info==key){
        return root;
    } else{
        if(key<root->info){
            search(root->left,key);
        } else {
            search(root->right,key);
        }
    } 
}

// void delNode(node *&root,int key){
//     if(root==NULL){
//         return;
//     }
//     if(key < root->info){
//         delNode(root->left,key);
//     } else if(key>root->info){
//         delNode(root->right,key);
//     } else{
//         if(root->left==NULL){
//             node *tmp = root->right;
//             delete root;
//             root = tmp;
//         } else if(root->right==NULL){
//             node *tmp = root->left;
//             delete root;
//             root = tmp;
//         } else{
//             node *tmp = root->right;
//             while(tmp->left!=NULL){
//                 tmp=tmp->left;
//             }
//             root->info=tmp->info;
//             delNode(root->right,tmp->info);
//         }
//     }
// }

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

void delNode2(node*&root,int key){
    if(root!=NULL){
        node *p = root;
        node  *parent =NULL;
        while(p!=NULL && p->info !=key){
            parent = p;
            if(p->info < key){
                p=p->right;
            }
            if(p->info>key){
                p=p->left;
            }
        } 

        if(p!=NULL){
            if(p->left!=NULL && p->right!=NULL){
                node *tmp =p->left;
                while(tmp->right!=NULL){
                {
                    parent = tmp;
                    tmp=tmp->right;
                }                
                p->info = tmp->info;
            } 
        }
    }
}
}

int getHeight(node *root){
    if(root!=NULL){
        int left = getHeight(root->left);
        int right = getHeight(root->right);

        return 1+(left>right?left:right);
    }
    return 0;
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
    insertNode(root,20);
    insertNode(root,10);
    insertNode(root,5);
    insertNode(root,17);
    insertNode(root,25);
    insertNode(root,23);
    insertNode(root,27);
    insertNode(root,60);
    insertNode(root,65);
    // LNR(root);
    // cout << endl;
    // delNode(root,40);
    // delNode(root,23);
    
    cout << getHeight(root);
    // LNR(root);
    return 1;
}