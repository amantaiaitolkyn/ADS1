#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int> d;
    int n; cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        if(i == 0){
            d.push_back(-1);
        }else{
            int r = i;
            int cnt = 0;
            for(int j = r - 1;j >= 0;j--){
                if(a[i] >= a[j]){
                    cnt++;
                    d.push_back(a[j]); 
                    break;
                }
            }
            if(cnt == 0){
                d.push_back(-1);
            }
        }
    }
   for(int i = 0;i < d.size();i++){
    cout << d[i] << " ";
   }

    return 0;
}