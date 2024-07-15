#include <iostream>
using namespace std;

struct term {
	int coef, exp;
};

struct node {
	term info;
	node *next;
};

void init(node *&head) {
	head = NULL;
}

node *createNode(term x) {
	node *p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}

void insertOrderList(node *&head, term x) {
	if (head == NULL) {
		head = createNode(x);
	}
	else {
		if (x.exp < head->info.exp) {
			node *p = createNode(x);
			p->next = head;
			head = p;
			return;
		}
		node *q = head;
		node *p = createNode(x);
		while (q != NULL && q->next->info.exp < x.exp) {
			q = q->next;
		}
		if (q->info.exp = x.exp) {
			q->info.coef += x.coef;
			return;
		}
		p->next = q->next;
		q->next = p;
	}

}


void output(node *head) {
	while (head != NULL) {
		cout << head->info.coef << "x^" << head->info.coef;
		if (head->next != NULL) {
			cout << "+";
		}
		head = head->next;
	}
	cout << endl;
}


int main() {
	node *head;
	init(head);
	term t1,t2,t3,t4,t5;

	t1.coef = 2;
	t1.exp = 2;
	insertOrderList(head, t1);

	t2.coef = 3;
	t2.exp = 3;
	insertOrderList(head, t2);
	
	/*t3.coef = 4;
	t3.exp = 4;
	insertOrderList(head, t3);

	t4.coef = 5;
	t4.exp = 5;
	insertOrderList(head, t4);*/

	output(head);


	return 1;
}