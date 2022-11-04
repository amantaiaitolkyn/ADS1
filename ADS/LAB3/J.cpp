#include <iostream>
#include <vector>
using namespace std;
long long workTime(vector<long long> bags,long long n,long long size){
    long long ans = 0;
    for(int i = 0;i <n;i++){
        ans += bags[i]/size;
        if(bags[i]%size){
            ans++;
        }
    }
    return ans;
}
int main(){
    long long n,h;
    cin >> n >> h;
    vector<long long> bags(n);
    for(int i =0;i < n;i++){
        cin >> bags[i];
    }
    long long l = 0,r = 1e18+123;

    while(l+1<r){
        long long m = (l+r) / 2;
        long long  time = workTime(bags,n,m);
        if(time <= h){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r;
    return 0;
}