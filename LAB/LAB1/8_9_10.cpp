#include <iostream>
using namespace std;
#define MAX 100

struct stack{
    int a[MAX],top;
};

void init(stack &s){
    s.top = -1;
}

bool isEmpty(stack s){
    return s.top == -1;
}

bool isfull(stack s){
    return s.top == MAX-1;
}

void push(stack &s,int x){
    s.top++;
    s.a[s.top] = x;
}

int pop(stack &s){
    return s.a[s.top--];
}

void output(stack s){
    int index=0;
    while(index<=s.top){
        cout << s.a[index++] << " ";
    }
    cout << endl;
}

void dectobin(int n){
    stack s;
    init(s);
    while (n>0){
        int tmp = n%2;
        push(s,tmp);
        n/=2;
    }
    while(!isEmpty(s)){
        int tmp = pop(s);
        cout << tmp ;
    }
}

void dectoX(int n,int coef){
    stack s;
    init(s);
    while (n>0){
        int tmp = n%coef;
        push(s,tmp);
        n/=coef;
    }
    while(!isEmpty(s)){
        int tmp = pop(s);
        cout << tmp ;
    }
}

int main(){
    // stack s;
    // init(s);
    // push(s,10);
    // push(s,15);
    // push(s,20);
    // push(s,25);
    // push(s,30);
    // output(s);
    // cout << pop(s) << endl;
    // output(s);
    int x;
    cout << "Nhap so can chuyen: ";
    cin >> x;
    cout << "Nhap he can chuyen: ";
    int n; cin >> n;
    dectoX(x,n);
    return 1;
}