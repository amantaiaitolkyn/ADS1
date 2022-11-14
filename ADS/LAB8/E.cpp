#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll pow[55];
ll p = 2;

void power(){
    pow[0] = 1; 
    for (int i = 1; i <= 55;i++) {
        pow[i] = pow[i - 1] * p;
    }
}

void checkHash(int n, vector<ll> &hs){
    for(int i = 0;i < n;i++){
        if(i > 0){
            cout << char((hs[i] - hs[i - 1]) / pow[i] + 97);
        }else{
            cout << char(hs[i] / pow[i] + 97);
        }
    }
}
int main(){
    int n; cin >> n;
    power();
    vector<ll> hs(n);
    for(int i = 0;i < n;i++){
        cin >> hs[i];
    }
    checkHash(n,hs);
    return 0;
}