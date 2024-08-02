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

void insertNode(node *&root,int x){
    if(root==NULL){
        root = createNode(x);
    } else{
        node *p = root;
        while(p!=NULL){
            if(p->info >  x){
                if(p->left == NULL){
                    p->left = createNode(x);
                    break;
                }
                p=p->left;
            } else if(p->info < x){
                if(p->right == NULL){
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

int count(node *root, int cnt){
    if(root!=NULL){
        count(root->left,cnt);
        cnt++;
        count(root->right,cnt);
    }
    return cnt;
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
    insertNode(root,25);
    insertNode(root,7);
    insertNode(root,15);
    cout << endl << count(root,0);
    LNR(root);
    return 1;
}