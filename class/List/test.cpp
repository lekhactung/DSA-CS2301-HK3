#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

void duyet(node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next; // cho head chuyen sang node ke tiep
    }
}

void themdau(node *&head, int x){
    //1. Cap phat dong node moi
    node *newNode = new node;
    newNode->data = x;
    newNode->next = newNode->prev = NULL;
    //2. Cho newNode tro vao head
    newNode->next = head;
    //3. Cho head tro nguoc lai node moi
    if(head != NULL){
        head->prev = newNode;
    }
    //4. Cap nhat head => newnode
    head = newNode;
}

int main(){
    node *head = NULL;
    for(int i = 10; i >= 1; i--){
        themdau(head, i);
    }
    duyet(head);
}