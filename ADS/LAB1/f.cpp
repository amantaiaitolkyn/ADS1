#include <iostream>
#include <queue>
using namespace std;

bool prime(int n){
    if (n <= 2) return 1;
    for (int i = 2; i * i <= n; i ++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    queue<int> de;
    int n;
    cin >> n;
    int cnt = 0;
    int i = 2;
    while(true){
        if (prime(i)){
            de.push(i);
        }
        if (de.size() == n) break;
        i++;
    }
    cout << i << endl;
    return 0;
}