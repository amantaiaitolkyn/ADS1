#include <cmath>
#include <iostream>
#include <set>
using namespace std;

bool prime(int n){
    if (n <= 2) return 1;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    int num1;
    int num2;
    for(int i = 2;i <= n;i++){
        num1 = i;
        num2 = n-i;
        if(prime(num1) && prime(num2)){
            cout << num1 << " " << num2;
            break;
        }
    }
    return 0;
}
