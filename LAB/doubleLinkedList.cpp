#include <iostream>
using namespace std;


struct node {
	int info;
	node *next, *prev;
};

struct doubleLinkedList {
	node *head;
	node *tail;
};

void init(doubleLinkedList &dl) {
	dl.head = NULL;
	dl.tail = NULL;
}

node *createNode(int x) {
	node *p = new node;
	p->info = x;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

node* findMax(doubleLinkedList dl) {
	node *res = dl.head;
	node *p = dl.head;
	while (p != NULL) {
		if (p->info > res->info)
			res = p;
		p = p->next;
	}
	return res;
}
node* findMin(doubleLinkedList dl) {
	node *res = dl.head;
	node *p = dl.head;
	while (p != NULL) {
		if (p->info < res->info)
			res = p;
		p = p->next;
	}
	return res;
}

node *search(doubleLinkedList dl, int key) {
	if (dl.head != NULL) {
		node *p = dl.head;
		while (p != NULL) {
			p = p->next;
			if (p->info != key)
				return p;
		}
	}
	return nullptr;
}


bool isEmpty(doubleLinkedList dl) {
	return dl.head == NULL;
}

void insertFirst(doubleLinkedList &dl, int x) {
	node *p = createNode(x);
	if (dl.head == NULL) {
		dl.head = dl.tail = p;
	}
	else {
		p->next = dl.head;
		dl.head->prev = p;
		dl.head = p;
	}
}

void insertLast(doubleLinkedList &dl, int x) {
	node *p = createNode(x);
	if (dl.head == NULL) {
		dl.head = dl.tail = p;
	}
	else {
		p->prev = dl.tail;
		dl.tail->next = p;
		dl.tail = p;
	}
}

void insertAfter(doubleLinkedList &dl, int key, int x) {
	node *tmp = search(dl, key);
	cout << tmp->info;
	if (tmp != NULL) {
		if (tmp == dl.tail) {
			insertLast(dl, x);
		}
		else {
			node *p = createNode(x);
			p->next = tmp->next;
			tmp->next->prev = p;
			p->prev = tmp;
			tmp->next = p;

		}
	}
	else {
		cout << "Khong tim thay! \n";
	}
}

void insertOrderedList(doubleLinkedList &dl, const int x) {
	node *p = createNode(x);
	if (dl.head == NULL) {
		dl.head = dl.tail = p;
		return;
	}

	if (p->info <= dl.head->info) {
		insertFirst(dl, x);
		return;
	}
	node *cur = dl.head;
	while (cur->next != NULL&&cur->next->info < p->info)
		cur = cur->next;

	if (cur == dl.tail) {
		insertLast(dl, x);
		return;
	}

	p->next = cur->next;
	cur->next->prev = p;

	p->prev = cur;
	cur->next = p;
}


void deleteNode(node *&p) {
	p->next = NULL;
	p->prev = NULL;
	delete p;
}

void delFirst(doubleLinkedList &dl) {
	if (dl.head != NULL) {
		node *p = dl.head;
		dl.head = dl.head->next;
		if (dl.head == NULL) {
			dl.tail = NULL;
		}
		else {
			dl.head->prev = NULL;
		}
		deleteNode(p);
	}
}

void delLast(doubleLinkedList &dl) {
	if (dl.head != NULL) {
		node *p = dl.tail;
		dl.tail = dl.tail->prev;
		if (dl.tail == NULL) {
			dl.head = NULL;
		}
		else {
			dl.tail->next = NULL;
		}
		deleteNode(p);
	}
}

void swap(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

void sortList(doubleLinkedList &dl) {
	for (node *i = dl.head; i!= NULL; i = i->next) {
		for (node *j = dl.head; j != NULL; j = j->next) {
			if (i->info > j->info) {
				swap(i->info, j->info);
			}
		}
	}
}

void destroyList(doubleLinkedList &dl) {
	while (!isEmpty(dl)) {
		delFirst(dl);
	}
}

void output(doubleLinkedList dl) {
	while (dl.head != NULL) {
		cout << dl.head->info << " ";
		dl.head = dl.head->next;
	}
	cout << endl;
}

void output2(doubleLinkedList dl) {
	while (dl.tail != NULL) {
		cout << dl.tail->info << " ";
		dl.tail = dl.tail->prev;
	}
	cout << endl;
}

int count (doubleLinkedList dl){
	int cnt = 0;
	while (dl.head != NULL) {
		cnt++;
		dl.head = dl.head->next;
	}
	return cnt;
}

int main() {
	doubleLinkedList dl;
	init(dl);
	insertLast(dl, 1);
	insertLast(dl, 3);
	insertLast(dl, 6);
	insertLast(dl, 2);
	insertLast(dl, 5);
	insertLast(dl, 4);
	insertLast(dl, 7);

	output(dl);
	output2(dl);
	cout << "====insert==== \n";	
	insertAfter(dl, 1, 10);
	output(dl);
	output2(dl);


	system("pause");
	return  1;
}