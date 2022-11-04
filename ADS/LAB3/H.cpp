#include <iostream>
using namespace std;

void binSearch(int p[],int l, int r, int x){
    while(l <= r){
        int m = (l + r)/2;
        if(p[m] >= x){
            r = m - 1;
        }
        if(p[m] <= x){
            l = m + 1;
        }
    }
    cout << r + 1 << endl;
}
int main(){
    int n, m;
    cin >> n >> m;
    int p[n];
    for(int i = 1;i <= n;i++){
        int x; cin >> x;
        if(i == 1){
            p[i] = x;
        }else{
            p[i] = p[i - 1] + x;
        }
    }
    for(int i = 1;i <= m;i++){
        int x; cin >> x;
        binSearch(p,1,n,x);
    }
    return 0;
}