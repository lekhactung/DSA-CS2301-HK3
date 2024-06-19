#include <bits/stdc++.h>
using namespace std;

//INPUT
// 8
// 1 2 3 1 2 1 0 3
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    set<int> s;
    int n;cin >> n;
    while(n--){
        int a;cin >> a;
        s.insert(a);
    }
    cout << s.size() <<  endl;
    if(s.find(2)!= s.end()){
        cout <<"FOUND!";
    } else {
        cout << "NOT FOUND!";
    } 
    return 0;
}