#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

#define MAX 50

struct stack
{
	char a[MAX];
	int top;
};

void init(stack &s) {
	s.top = -1;
}

void push(stack &s, char x) {
	if (s.top < MAX) {
		s.a[++s.top] = x;
	}
}

bool isEmpty(stack s) {
	return s.top == -1;
}

char pop(stack &s) {
	if (!isEmpty(s)) {
		return s.a[s.top--];
	}
}

void printStack(stack s) {
	for (int i = 0; i <= s.top; i++)
		cout << s.a[i] << " ";
	cout << endl;
}

struct node {
	char* info;
	node *next;
};

struct queue {
	node *head;
};

void init(queue &q) {
	q.head == NULL;
}

node *createNode(char *x) {
	node *p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}

void enqueue(queue &q, char* x) {
	if (q.head == NULL) {
		q.head = createNode(x);
	}
	else {
		node *plast = q.head;
		while (plast->next != NULL) {
			plast = plast->next;
		}
		plast->next = createNode(x);
		plast = plast->next;
	}
}

char *dequeue(queue &q) {
	char *data = nullptr;
	if (q.head != NULL) {
		node *p = q.head;
		data = p->info;
		q.head = q.head->next;
		p->next == NULL;
		delete p;
	}
	return data;
}

int priority(char x) {
	switch (x)
	{
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;

	}
	return 0;
}

void infixToPosfix(char str[]) {
	stack s;
	init(s);
	queue posfix;
	init(posfix);

	char *p = strtok(str," ");
	while(p){
		if(isdigit(*p)){
			enqueue(posfix,p);
		} else if(*p =='('){
			push(s,*p);
		} else if(*p==')'){
			char op = pop(s);
		}


		p = strtok(NULL," ");
	}
}

int main() {
	char str[] = "2 + 4 - ( 5 - 3 ) / 2 + 3 - 1 * 5";
	infixToPosfix(str);
	return 1;
}