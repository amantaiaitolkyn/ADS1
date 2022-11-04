#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    sort(a, a + n);
    int k; cin >> k;
    for(int i = 0 ;i < k;i++){
        int x; cin >> x;
        int sum = 0;
        int cnt = 0;
        for(int j = 0;j < n;j++){
            if(a[j] > x){
                break;
            }else{
                sum+= a[j];
                cnt++;
            }
        }
        cout << cnt  << " " << sum << endl;
    }
    return 0;
}