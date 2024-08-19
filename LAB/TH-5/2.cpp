#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#define M 17 

struct value {
	char* key;
	int freq;
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
		ht.h[i].value.key = "";
		ht.h[i].value.freq = 0;
		ht.h[i].next = -1;
	}
	ht.r = M - 1;
}

int hashFunc(char* str) {
	int key = 0;
	for (int i = 0; i < strlen(str); i++) {
		key += (int) *(str + i) *(i + 1);
	}
	return key%M;
}

void insert(hashTable &ht, char* str) {
	int k = hashFunc(str);
	if (ht.h[k].value.key == NULL) {
		ht.h[k].value.key = str;
		ht.h[k].value.freq++;
	}
	else {
		if (ht.h[k].value.key == str) {
			ht.h[k].value.freq += 1;
		}
		else {
			ht.h[ht.r].value.key = str;
			ht.h[ht.r].value.freq++;
			while (ht.h[k].next != -1) {
				k = ht.h[k].next;
			}
			ht.h[k].next = ht.r;
			if (ht.r > 0 && ht.h[k].value.key != NULL) {
				ht.r--;
			}
		}
	}
}

void printHash(hashTable ht) {
	for (int i = 0; i < M; i++) {
		if (ht.h[i].value.key != NULL) {
			cout << "BUCKET : " << i << endl
				<< "Value: " << ht.h[i].value.key << "\t Freq : " << ht.h[i].value.freq << "\t Next: " << ht.h[i].next << endl;
		}
	}
}

int main() {
	hashTable ht;
	init(ht);
	char* s = "apple banana apple cherry date banana cherry fig grape date";
	
	char *p = strtok(s, " ");
	while (p != NULL) {
		insert(ht, p);
		//cout << p << " ";
	//cout << hashFunc("p") << endl;
		p = strtok(NULL, " ");
	}
	printHash(ht);
	system("pause");
	return 1;
}