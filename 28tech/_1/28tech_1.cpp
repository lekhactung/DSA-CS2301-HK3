#include <bits/stdc++.h>
using namespace std;

//INPUT
// 7
// 1 58 
// 2
// 2
// 1 52
// 1 81
// 1 12
// 1 2 

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // srand(time(NULL));
    vector <int> v;
    int n; cin >> n;
    while(n>0){
        int a,b;
        cin >> a;
        if(a==1){
            int b; cin >> b;
            v.push_back(b);
        } else {
            if(!v.empty()){
                v.pop_back();
            }
        }
        n--;
    }

    for(auto x : v){
        cout << x << " ";
    }

    return 0;
}