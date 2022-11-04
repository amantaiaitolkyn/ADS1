#include <iostream>
using namespace std;
int binSearch(int a[],int l,int r,int x){
    while(l <= r){
        int m = (l + r)/2;
        if(a[m] == x){
            return x;
        }
        if(a[m] > x) r = m - 1;
        if(a[m] < x) l = m + 1;
    }
    return false;
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int x; cin >> x;
    if(binSearch(a,0,n,x)){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}