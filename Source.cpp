#include <iostream>
using namespace std;
#define M 7 
struct node{
	int val, next;
};

struct hashTable {
	node h[M];
	int r;
};

void init(hashTable &ht) {
	for (int i = 0; i < M; i++) {
		ht.h[i].val = -1;
		ht.h[i].next = -1;
	}
	ht.r = M - 1;
}

int hashFunc(int x) {
	return x%M;
}

void insert(hashTable &ht, int x) {
	int k = hashFunc(x);
	if (ht.h[k].val == -1) {
		ht.h[k].val = x;
	}
	else {
		ht.h[ht.r].val = x;
		while (ht.h[k].next != -1) {
			k = ht.h[k].next;
		}
		ht.h[k].next = ht.r;
		if (ht.r > 0 && ht.h[ht.r].val != -1) {
			ht.r--;
		}
	}
}

int search(hashTable ht, int x) {
	int k = hashFunc(x);
	while (k != -1 && ht.h[k].val != x) {
		k = ht.h[k].next;
	}
	return k;
}

void del(hashTable &ht, int x) {
	int k = hashFunc(x);
	while (k != 1 && ht.h[k].val != x) {
		k = ht.h[k].next;
	}
	
	if (k == -1) {
		return;
	}
	int prev = -1;
	while (ht.h[k].next != -1) {
		prev = k;
		k = ht.h[k].next;
		ht.h[prev].val= ht.h[k].val;
	}

	ht.h[k].val = -1;
	if(prev !=-1){
		ht.h[prev].next = -1;
	}
	if (ht.r < k) {
		ht.r = k;
	}
}

void printHash(hashTable ht) {
	for(int i = 0; i < M; i++) {
		if (ht.h[i].val!=-1) {
			cout << "Bucket " << i << " : " << ht.h[i].val << " | " << ht.h[i].next;
			cout << endl;
		}
	}
}

int main() {
	hashTable ht;
	init(ht);
	insert(ht, 10);
	insert(ht, 30);
	insert(ht, 7);
	insert(ht, 35);
	insert(ht, 21);
	cout << "////////////";
	printHash(ht);
	del(ht, 35);
	insert(ht, 13);
	cout << "////////////";
	printHash(ht);
	system("pause");
	return 1;
}