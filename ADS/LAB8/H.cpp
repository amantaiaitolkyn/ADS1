#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll D=256, m = 1e9, p=31, N = 1e5;
int a[N];

vector<ll> getHs(string s){
    vector<ll> h(s.size());
    ll p_pow = 1;
    for(int i=0; i<s.size(); i++){
        h[i] = (s[i] - 'a' + 1)*p_pow%m;
        if(i!=0) h[i] = (h[i] + h[i-1])%m;
        p_pow=p_pow*p%m;
    }
    return h;
}


ll getH(string s){
    ll h=0;
    ll p_pow=1;
    for(int i=0; i<s.size(); i++){
        h = (h + (s[i] -'a' + 1)*p_pow%m)%m;
        p_pow=p_pow*p%m;
    }
    return h;
}

bool search(pair<ll,string> h, string txt){
    vector<ll> hs = getHs(txt);
    for(int i=0; i<txt.size()-h.second.size()+1; i++){
        ll hdif = hs[i+h.second.size()-1];
        if(i!=0){
            hdif-=hs[i-1];
            h.first=h.first*p%m;
        }
        if(hdif<0)hdif+=m;
        if(h.first==hdif)return true;

    }
    return false;

}


string findi(vector<string> v){
    string maxn="";
    int maxnum=0, l;
    ll h1=0, p_pow1 = 1;
    a[N] = {0};
    for(int i=0; i<v[1].size(); i++){
        ll h =0;
        h1 = (v[1][i] - 'a' +1)*p_pow1%m; 
        ll p_pow=1;
        pair<ll, string> hstr;
        for(int j=v[0].size()-1; j>=0; j--){
            h = (v[0][j] - 'a' + 1)*p_pow%m;
            if(h == h1) a[j +1] = a[j] + 1; else a[j+1] = 0;
            if(a[j+1]>maxnum) {
                maxnum = a[j+1];
                l = j-maxnum+1;
            }
        }
    }
    if(maxnum==0)return "";
    return v[0].substr(l, maxnum);


}

int main(){
    int n; cin>>n;
    string str, s; cin >> str;
    for(int i=0; i<n-1; i++){
        cin >> s;
        vector<string> v;
        v.push_back(str); v.push_back(s);
        str = findi(v);

    }
    cout << str;



}