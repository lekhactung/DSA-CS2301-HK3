#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX 100


struct stack {
	int a[MAX],top;
};

void init(stack &s) {
	s.top = -1;
}

bool isEmpty(stack s) {
	return s.top == -1;
}

bool isFull(stack s) {
	return s.top == MAX - 1;
}

void push(stack &s, int x) {
		s.a[++s.top] = x;
}

int pop(stack &s) {
	return s.a[s.top--];
}

void output(stack s) {
	for (int i = s.top; i >= 0; i--) {
		cout << s.a[i] << " ";
	}
	cout << endl;
}

void output2(stack s) {
	for (int i = 0 ; i <=s.top; i++) {
		cout << s.a[i] << " ";
	}
	cout << endl;
}

void dectobin(int n) {
	stack s;
	init(s);
	while (n != 0) {
		push(s, n % 2);
		n /= 2;
	}
	output(s);
}

void calExp(char str[]) {
	stack s;
	init(s);
	char *p = strtok(str, " ");
	while (p != NULL) {
		if (isdigit(*p)) {
			push(s, atoi(p));
			output(s);
		}
		else {
			int b = pop(s);
			int a = pop(s);
			switch (*p)
			{
			case '+' : 
				push(s, a + b);
			case '-':
				push(s, a - b);
			case '*':
				push(s, a * b);
			case '/':
				push(s, a / b);
			default:
				break;
			}
		}
		p = strtok(NULL, " ");
	}
	cout << pop(s);
}

int main() {
	//dectobin(23);
	char str[] = "5 1 2 + 4 * + 3 +";
	calExp(str);


	system("pause");
	return 1;
}