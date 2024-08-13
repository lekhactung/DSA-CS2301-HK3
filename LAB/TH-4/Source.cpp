#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int info;
	node *left, *right;
	int height;
};

void init(node *&root) {
	root = NULL;
}

int getHeight(node *root) {
	if (root == NULL) {
		return 0;
	}
	return root->height;
}

void updateHeight(node *&root) {
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
}

void rightRotate(node *&root) {
	node *x = root->left;
	root->left = x->right;
	x->right = root;
	updateHeight(root);
	updateHeight(x);
	root = x;
}

void leftRotate(node *&root) {
	node *x = root->right;
	root->right = x->left;
	x->left = root;
	updateHeight(root);
	updateHeight(x);
	root = x;	
}

node *createNode(int x) {
	node *p = new node;
	p->info = x;
	p->left = p->right = NULL;
	p->height = 1;
	return p;
}

void insert(node *&root, int x) {
	if (root == NULL) {
		root = createNode(x);
	}
	else {
		if (root->info > x) {
			insert(root->left, x);
		}
		else if (root->info < x) {
			insert(root->right, x);
		}
		else {
			return;
		}
		updateHeight(root);
		int val = getHeight(root->left) - getHeight(root->right);
		if (val > 1 && root->left->info> x) {
			rightRotate(root);
		}
		else if (val >1 && root->left->info <x) {
			leftRotate(root->left);
			rightRotate(root);
		}
		else if (val < -1 && root->right->info < x) {
			leftRotate(root);
		}
		else if (val < -1 && root->right->info > x) {
			rightRotate(root->right);
			leftRotate(root);
		}
	}
}

void searchStandFor(node *&cur, node *&temp) {
	if (temp->left != NULL) {
		temp = temp->left;
	}
	else {
		cur->info = temp->info;
		temp = temp->right;
		cur = temp;
	}
}

int getBalance(node *root) {
	return getHeight(root->left) - getHeight(root->right);
}

void delNode(node *&root, int key) {
	if (root == NULL) {
		return;
	} 
	if (key < root->info) {
		delNode(root->left, key);
	}
	else if (key > root->info) {
		delNode(root->right, key);
	}
	else {
		node *cur = root;
		if (root->left == NULL) {
			root = root->right;
		}
		else if (root->right == NULL) {
			root = root->left;
		}
		else {
			searchStandFor(cur, root->right);
		}
	}

	if (root == NULL) {
		return;
	} 
	updateHeight(root);

	int val = getBalance(root);
	if (val > 1 &&getBalance(root->left) >=0 ){
		rightRotate(root);
	}
	else if (val >1 && getBalance(root->left) <0) {
		leftRotate(root->left);
		rightRotate(root);
	}
	else if (val < -1 && getBalance(root->right)<=0) {
		leftRotate(root);
	}
	else if (val < -1 && getBalance(root->right)>0) {
		rightRotate(root->right);
		leftRotate(root);
	}
	
}

//
//int demla(node *root) {
//	if (root == NULL) {
//		return 0;
//	}
//	else {
//		if (root->left == NULL && root->right == NULL) {
//			return 1;
//		}
//		else {
//			return demla(root->left) + demla(root->right);
//		}
//	}
//}

void nodeLa(node *root, int &count) {
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			count += 1;
		}
		nodeLa(root->left, count);
		nodeLa(root->right, count);
	}
}

int calHeight(node *root) {
	if (root != NULL) {
		return 1 + max(getHeight(root->left), getHeight(root->right));
	}
	return 0;
}

void lnr(node *root) {
	if (root != NULL) {
		lnr(root->left);
		cout << root->info << "(" << root->height << ") ";
		lnr(root->right);
	}
}

void nlr(node *root) {
	if (root != NULL) {
		cout << root->info << "(" << root->height << ") ";
		nlr(root->left);
		nlr(root->right);
	}
}

int main(){
	node *root;
	init(root);
	insert(root, 40);
	insert(root, 20);
	insert(root, 60);
	insert(root, 15);
	insert(root, 30);

	insert(root, 10);
	insert(root, 5);

	nlr(root);
	cout << endl;
	//cout << calHeight(root);
	delNode(root, 20);
	nlr(root);

	return 1;
}