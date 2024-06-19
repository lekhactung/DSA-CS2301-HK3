#include <bits/stdc++.h>
using namespace std;

//INPUT

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    set<int> s;
    for(int i=0;i<50;i++){
        int a = rand()%10+1;
        cout << a << " "; 
        s.insert(a);
    } 
    cout << endl;
    
    for(auto it = s.begin(); it != s.end();it++){
        cout << *it << " "; 
    }


    // for(auto x: s){
    //     cout << x <<" ";
    // }
    return 0;
}