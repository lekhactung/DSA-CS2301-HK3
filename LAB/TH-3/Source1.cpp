#include <iostream>
#include <fstream>
using namespace std;

void swap(long &a, long &b) {
	int c = a;
	a = b;
	b = c;
}

void interchangeSort(long *a, long n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[i]) {
				swap(a[i], a[j]);
			}
		}
	}
}

void selectionSort(long *a, long n) {
	for (int i = 0; i < n - 1; i++) {
		int pos = i;
		for (int j = i + 1; j < n; j++) {
			if(a[j] < a[pos]){
				pos = j;
			}
		}
		if (pos != i) {
			swap(a[i], a[pos]);
		}
	}
}

void insertionSort(long *a, long n) {
	for(int i = 0; i < n; i++) {
		int val = a[i];
		int pos = i - 1;
		while (pos >= 0 && a[pos] > val) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = val;
	}
}

void bubbleSort(long *a, long n) {
	for (int i = 0; i < n-1; i++) {
		for (int j =0; j < n-i-1; j++) {
			if (a[j + 1] < a[j]) {
				swap(a[j + 1], a[j]);
			}
		}
	}
}

void quickSort(long *a, int left, int right) {
	int l = left, r = right;
	int pivot = a[(left + right) / 2];
	while (l <= r) {
		while (a[l]<pivot) {
			l++;
		}
		while (a[r]>pivot) {
			r--;
		}
		if (l <= r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	if (left<r) {
		quickSort(a, left, r);
	}
	if (l<right) {
		quickSort(a, l, right);
	}
}


void heapify(long *a, int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l<n && a[l] > a[largest]) {
		largest = l;
	}
	if (r<n && a[r] && a[r] > a[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(a[largest], a[i]);
		heapify(a, n, largest);
	}
}

void heapsort(long *a, int n) {
	int i = n / 2 - 1;
	while (i >= 0) {
		heapify(a, n, i);
		i--;
	}
	int right = n - 1;
	while (right>0) {
		swap(a[0], a[right]);
		if (right>0) {
			heapify(a, right, 0);
		}
		right--;
	}
}

void output(long *a, long n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}

int main() {
	long *a= NULL, n;
	//docfile(a, n);

	ifstream ifs;
	ifs.open("DaySo.txt");
	if (ifs.is_open()) {
		ifs >> n;
		int i = 0;
		a = new long[n];
		
		for (int i = 0; i < n; i++) {
			ifs >> a[i];
		}
	}
	else {
		cout << "Khong mo duoc file";
	}
	ifs.close();

	//bubbleSort(a, n);
	//quickSort(a, 0, n - 1);
	heapsort(a, n);

	ofstream ofs;
	ofs.open("output.txt");
	if (ofs.is_open()) {
		for (int i = 0; i < n; i++) {
			ofs << a[i] << endl;
		}
	}
	ofs.close();
	delete[]a;
	system("pause");

	return 1;
}