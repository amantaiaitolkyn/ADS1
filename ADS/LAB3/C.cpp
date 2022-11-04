#include <iostream>
using namespace std;
int main(){
    int n;
    int q;
    cin >> n >> q;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < q;i++){
        int cnt = 0;
        int l1; int r1; int l2; int r2;
        cin >> l1 >> r1 >>l2 >>r2;
        for(int j = 0;j < n;j++){
            if(a[j] >= l1 && a[j] <= r1 || a[j] >= l2 && a[j] <= r2){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}