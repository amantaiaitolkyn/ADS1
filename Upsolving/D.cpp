#include <cmath>
#include <iostream>
#include <set>
using namespace std;

bool prime(int n){
    if (n <= 2) return 1;
    for (int i = 2; i <= sqrt(n) + 1; i ++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int n;
    cin >> n;
    set<int> st;
    for(int i = 2;i <= n;i++){
        while(n%i==0){
            if(prime(i)){
                st.insert(i);
            }
            n = n/i;
        }
    }
    cout << st.size();
    return 0;
}

