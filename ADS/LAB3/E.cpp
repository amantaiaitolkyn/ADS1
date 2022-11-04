#include <iostream>
#include <vector>
using namespace std;

int pasturesCnt(vector<pair<pair<int,int >,pair< int,int> > > p,int n,int x){
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(p[i].first.first <= x &&  p[i].first.second <= x && p[i].second.first <= x && p[i].second.second <= x){
            ans++;
        }
    }
    return ans;
}

int main(){
    int n; int k;
    cin >> n >> k;
    vector<pair<pair<int,int >,pair< int,int> > >p(n);
    for(int i = 0;i < n;i++){
        int x1,y1;
        int x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        p[i].first.first = x1;
        p[i].first.second = y1;
        p[i].second.first = x2;
        p[i].second.second = y2;
    }

    int l = 0; int r = 1e9+2;
    while(l + 1 < r){
        int m = (l+r)/2;
        if(pasturesCnt(p,n,m) >= k){
            r = m;
        }else{
            l = m;
        }
    }

    cout << r;

    return 0;
}