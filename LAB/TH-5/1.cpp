#include <iostream>
using namespace std;
#define M 7 

struct value {
	int key, freq;
};

struct node {
	value value;
	int next;
};

struct hashTable {
	node h[M];
	int r;
};

void init(hashTable &ht) {
	for (int i = 0; i < M; i++) {
		ht.h[i].value.key = -1;
		ht.h[i].value.freq = 0;
		ht.h[i].next = -1;
	}
	ht.r = M - 1;
}

int hashFunc(int x) {
	return x%M;
}

void insert(hashTable &ht, int x) {
	int k = hashFunc(x);
if (ht.h[k].value.key == -1) {
	ht.h[k].value.key = x;
	ht.h[k].value.freq++;
	}
	else {
		if (ht.h[k].value.key == x) {
			ht.h[k].value.freq += 1;
		}
		else {
			ht.h[ht.r].value.key = x;
			ht.h[ht.r].value.freq++;
			while (ht.h[k].next != -1) {
				k = ht.h[k].next;
			}
			ht.h[k].next = ht.r;
			if (ht.r > 0 && ht.h[k].value.key != -1) {
				ht.r--;
			}
		}
	}
}

void printHash(hashTable ht) {
	for (int i = 0; i < M; i++) {
		if(ht.h[i].value.key != -1){
			cout << "BUCKET : " << i << endl
				<< "Value: " << ht.h[i].value.key << "\t Freq : " << ht.h[i].value.freq << "\t Next: " << ht.h[i].next << endl;
		}
	}
}

int main() {
	hashTable ht;
	init(ht);
	
	int a[] = { 15, 7, 9, 7, 13, 15, 20, 11, 9, 15 };
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++) {
		insert(ht, a[i]);
	}
	printHash(ht);
	system("pause");
	return 1;
}