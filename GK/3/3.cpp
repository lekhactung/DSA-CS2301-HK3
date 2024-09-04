#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* createList(int n) {
    if (n <= 0) return nullptr;
    
    Node* head = createNode(1);
    Node* current = head;
    
    for (int i = 2; i <= n; ++i) {
        current->next = createNode(i);
        current = current->next;
    }
    current->next = head; // Make it circular
    
    return head;
}

int josephus(Node*& head, int m) {
    if (head == nullptr) return -1;

    Node* current = head;
    Node* prev = nullptr;

    while (current->next != current) {
        for (int i = 1; i < m; ++i) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        if (current == head) head = prev->next;
        delete current;
        current = prev->next;
    }

    int winner = current->data;
    delete current;
    head = nullptr;
    return winner;
}

int findStartingPosition(Node* head, int k) {
    if (head == nullptr) return -1;

    Node* current = head;
    int count = 1;
    do {
        if (current->data == k) return count;
        current = current->next;
        count++;
    } while (current != head);

    return -1; // k not found
}

void deleteList(Node*& head) {
    if (head == nullptr) return;
    
    Node* current = head->next;
    while (current != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
    head = nullptr;
}

int main() {
    int n, m, k;
    cout << "Nhap so nguoi choi (n): ";
    cin >> n;
    
    Node* head = createList(n);

    cout << "Nhap so m  (Ng dem den m la ng bi loai): ";
    cin >> m;

    int winner = josephus(head, m);
    cout << "Ng chien thang la: " << winner << endl;

    head = createList(n); // Tạo lại danh sách để tìm vị trí bắt đầu
    cout << "Nhap vi tri k cua nguoi chien thang: ";
    cin >> k;

    int startingPosition = findStartingPosition(head, k);
    cout << "Nguoi bat dau dem la nguoi thu: " << startingPosition << endl;

    deleteList(head);
    return 0;
}