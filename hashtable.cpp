#include <iostream>
using namespace std;

#define M 7

struct node {
	int info;
	node *next;
};

void init(node *heads[]) {
	for (int i = 0; i < M; i++) {
		heads[i] = NULL;
	}
}

node *createNode(int x) {
	node *p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}

int hashFunc(int key) {
	return key % M;
}

void insert(node *heads[], int x) {
	int k = hashFunc(x);
	if (heads[k] == NULL) {
		heads[k] = createNode(x);
	}
	else {
		/*if (heads[k]->info > x) {
			node *p = createNode(x);
			p->next = heads[k];
			heads[k] = p;
		}
		else {
			node *newNode = createNode(x);
			node *p = heads[k];
			while (p != NULL &&p->info < x) {
				p = p->next;
			}
			newNode->next = p->next;
			p->next = newNode;
		}*/
		node *newNode = createNode(x);
		node *p = heads[k];
		if (x < p->info) {
			newNode->next = heads[k];
			heads[k] = newNode;
		}
		else {
			while (p->next != NULL && p->next->info < x) {
				p = p->next;
			} 
			newNode->next = p->next;
			p->next = newNode;
		}
	}
}

void print(node *heads[]) {
	for (int i = 0; i < M; i++) {
		if (heads[i] != NULL) {
			cout << "BUCKET " << i << ": ";
			node *p = heads[i];
			while (p != NULL) {
				cout << p->info << " ";
				p = p->next;
			}
		cout << endl;
		}
	}
}

int main() {
	node *heads[M];
	init(heads);
	insert(heads, 10);
	insert(heads, 7);
	insert(heads, 21);
	insert(heads, 13);
	insert(heads, 14);
	insert(heads, 15);
	insert(heads, 16);
	print(heads);
	system("pause");
	return 1;
}