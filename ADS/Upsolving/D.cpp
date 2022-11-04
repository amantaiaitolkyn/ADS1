// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     int n; cin >> n;
//     int cnt = 0;
//     vector<char> prime (n+1,true);
//     prime[0] = prime[1] = false;
//     for(int i = 2;i<=n;++i){
//         if(prime[i]){
//             if(n % i == 0){
//                 cnt++;
//             }
//             if(i*1ll*i <= n){
//                 for(int j = i*i;j<=n;j+=i){
//                     prime[j] = false;
//                 }
//             }
//         }
//     }
//     cout << cnt;
//     return 0;
// }

#include <iostream>
#include <deque>
using namespace std;

bool prime(int n){
    if (n <= 2) return 1;
    for (int i = 2; i * i <= n; i ++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    deque<int> de;
    int n;
    cin >> n;
    int cnt = 0;
    for(int i= 2;i <= n;i++){
        if(prime(i)){
            if(n % i== 0){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}