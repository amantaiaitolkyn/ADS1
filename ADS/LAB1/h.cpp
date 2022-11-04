#include <iostream>
#include <deque>
using namespace std;

bool prime(int n){
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i ++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    deque<int> de;
    int n;
    cin >> n;
    if(prime(n)){
        de.push_back(n);
    }
    if(de.size() > 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}