#include <iostream>
#include <math.h>
using namespace std;

int prime[10000001];

void sang(){
	for(int i=0;i<=10000000;i++){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i=0;i<=sqrt(10000000);i++){
        if(prime[i]==1){
            for(int j = i*i;j<=10000000;j+=i){
                prime[j]=0;
            }
        }
    }
}

int main(){
    int n;cin >> n;
	sang();
	if(prime[n]){
        cout << "La SNT";
    } else{
        cout << "Khong la SNT";
    }
	return 0;
}