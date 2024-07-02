#include <bits/stdc++.h> 
using namespace std;
#define MAX 100

struct Stack{
    int a[MAX],top;
};

void init(Stack &s){
    s.top = -1;
}

void push(Stack &s,int x){
    s.top++;
    s.a[s.top] = x;
}

int pop(Stack &s){
    return s.a[s.top--];
}

bool isEmpty(Stack s){
    return s.top =-1;
}

void output(Stack s){

}

void dectobin(int n){
    Stack s;
    init(s);
    while(n!=0){
        int x = n%2;
        push(s,x);
        n/=2;
    }
    while(!isEmpty(s)){
        int tmp = pop(s);
        cout << tmp;
    }
}

int main(){
    dectobin(13);
    
    return 1;
}