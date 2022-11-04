#include <iostream>
#include <deque>
using namespace std;

bool prime(int n){
    if (n <= 2) return 1;
    for (int i = 2; i * i <= n; i ++){
        int ind = i;
        if (n % i == 0 && ind % i == 0) return 0;
    }
    return 1;
}

int main(){
    deque<int> de;
    int n;
    cin >> n;
    int cnt = 1;
    int i = 3;
    while(true){
        if (prime(i)){
            cnt++;
            if(prime(cnt)){
                de.push_back(i);
                if (de.size() == n) break;
            }
        }
        i++;
    }
    for(i = 0;i < de.size();i++){
        cout << de[de.size() - i - 1];
        break;
    }
    return 0;
}