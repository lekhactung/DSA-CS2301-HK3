#include <iostream>
using namespace std;

#define M 99

struct Node
{
    int key;
    Node *next;
};

Node *HashTable[M];

void InitHashTable(Node *HashTable[M])
{
    for (int i = 0; i < M; i++)
        HashTable[i] = NULL;
}

int Hash(int k)
{
    return k % M;
}

void AddTail(Node *&l, int k)
{
    Node *newNode = new Node{k, NULL};
    if (l == NULL)
    {
        l = newNode;
    }
    else
    {
        Node* p = l;
        while (p != NULL && p->next != NULL)
            p = p->next;
        p->next = newNode;
    }
}

void InsertNode(Node *HashTable[M], int k)
{
    int i = Hash(k);
    AddTail(HashTable[i], k);
}

void DeleteHead(Node *&l)
{
    if (l != NULL)
    {
        Node *p = l;
        l = l->next;
        delete p;
    }
}

void DeleteAfter(Node *&q)
{
    Node *p = q->next;
    if (p != NULL)
    {
        q->next = p->next;
        delete p;
    }
}

void DeleteNode(Node *HashTable[M], int k)
{
    int i = Hash(k);
    Node *p = HashTable[i];
    Node *q = p;
    while (p != NULL && p->key != k)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        cout << k << " not found!" << endl;
    else if (p == HashTable[i])
        DeleteHead(HashTable[i]);
    else
        DeleteAfter(q);
}

Node *SearchNode(Node *HashTable[M], int k)
{
    int i = Hash(k);
    Node *p = HashTable[i];
    while (p != NULL && p->key != k)
        p = p->next;
    if (p == NULL)
        return NULL;
    return p;
}

void Traverse(Node *p)
{
    while (p != NULL)
    {
        cout << p->key << ' ';
        p = p->next;
    }
    cout << endl;
}

void TraverseHashTable(Node *HashTable[M])
{
    for (int i = 0; i < M; i++)
    {
        if(HashTable[i]!=NULL){
            cout << "Bucket " << i << ": ";
            Traverse(HashTable[i]);
        }
    }
}

int CountNodesInBucket(Node *bucket)
{
    int count = 0;
    Node *p = bucket;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void countNode(Node *HashTable[M]){
    for (int i = 0; i < M; i++)
    {
        if(HashTable[i]!=NULL){
            cout << "Bucket " << i << " :  " <<CountNodesInBucket(HashTable[i]) << endl;
        }
    }
}

int main()
{
    Node *HashTable[M];
    InitHashTable(HashTable);

    InsertNode(HashTable, 0);
    InsertNode(HashTable, 1);
    InsertNode(HashTable, 2);
    InsertNode(HashTable, 3);
    InsertNode(HashTable, 10);
    InsertNode(HashTable, 13);
    InsertNode(HashTable, 9);
    InsertNode(HashTable, 11);
    InsertNode(HashTable, 100);
    InsertNode(HashTable, 112);
    InsertNode(HashTable, 212);
    InsertNode(HashTable, 334);
    InsertNode(HashTable, 101);
    InsertNode(HashTable, 123);
    InsertNode(HashTable, 925);
    InsertNode(HashTable, 118);

    // cout << "HashTable:n";   
    TraverseHashTable(HashTable);
    // countNode(HashTable);
    // DeleteNode(mHashTable, 3);
    // DeleteNode(mHashTable, 13);
    // DeleteNode(mHashTable, 9);
    // cout << "HashTable after Delete:n";
    // TraverseHashTable(mHashTable);

    // Node *result = SearchNode(mHashTable, 10);
    // if (result == NULL)
    //     cout << "Not found!";
    // else
    //     cout << "Found!";

    // std::cout << std::endl;
    system("pause");
    return 0;
}