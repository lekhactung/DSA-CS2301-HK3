#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define M 7 

struct user {
	int id;
	char *userName;
	int freq;
};

struct node {
	user value;
	int next;
};

struct hashTable {
	node h[M];
	int r;
};

void init(hashTable &ht) {
	for (int i = 0; i < M; i++) {
		ht.h[i].value.id = -1;
		ht.h[i].value.freq = 0;
		ht.h[i].next = -1;
		ht.h[i].value.userName = nullptr;
	}
	ht.r = M - 1;
}

int hashFunc(int x) {
	return x%M;
}

void insert(hashTable &ht, user x) {
	int k = hashFunc(x.id);
	if (ht.h[k].value.id == -1) {
		ht.h[k].value.id = x.id;
		ht.h[k].value.userName = x.userName;
		ht.h[k].value.freq = 1;
	}
	else {
		if (ht.h[k].value.id == x.id) {
			ht.h[k].value.freq += 1;
		}
		else {
			ht.h[ht.r].value.id = x.id;
			ht.h[ht.r].value.freq++;
			while (ht.h[k].next != -1) {
				k = ht.h[k].next;
			}
			ht.h[k].next = ht.r;
			if (ht.r > 0 && ht.h[k].value.id != -1) {
				ht.r--;
			}
		}
	}
}

void printHash(hashTable ht) {
	for (int i = 0; i < M; i++) {
		if (ht.h[i].value.id != -1) {
			cout << "ID: " << ht.h[i].value.id << " \t USERNAME : " << ht.h[i].value.userName << " \t So lan truy cap : " << ht.h[i].value.freq << endl;
		}
	}
}

int main() {
	hashTable ht;
	init(ht);

	ifstream ifs("user.txt");
	if (ifs.is_open()) {
		while (!ifs.eof()) {
			user u;
			ifs >> u.id;
			ifs.ignore();
			ifs >> u.userName;
			insert(ht, u);
		}
		ifs.close();
	}
	
	// user u1;
	// u1.id = 1001;
	// u1.userName = "lekhactung";
	// insert(ht,u1);
	printHash(ht);


	system("pause");
	return 1;
}