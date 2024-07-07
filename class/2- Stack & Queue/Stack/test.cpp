#include <iostream> 
using namespace std;

struct node {
    //VUNG THONG TIN
    int info;
    //VUNG DIA CHI
    node *next;
};

void init(node *&head){
    head = NULL;
}

int main(){
    node *head;
    init(head);

    return 1;
}