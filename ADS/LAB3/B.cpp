#include <iostream>
#include <vector>
using  namespace std;

long long block(vector<long long> num,long long n, long long x){
    long long  cur = 0; long long ans = 0;
    for(int i = 0; i < n;i++){
        if(num[i] > x){
            return 1e18+123;
        }
        if(cur + num[i] > x){
            ans++;
            cur = num[i];
        }else{
            cur += num[i];
        }
    }
    if(cur){
        ans++;
    }
    return ans;

}
int main(){
    long long n,k;
    cin >> n >>k;
    vector<long long> num(n);
    for(int i = 0;i < n;i++){
        cin >> num[i];
    }
    long long l = 0 , r = 1e18+123;
    while(l+1 < r){
        long long m =(l+r)/2;
        long long blocks = block(num,n,m);
        if(blocks <= k){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r;
    return 0;
}