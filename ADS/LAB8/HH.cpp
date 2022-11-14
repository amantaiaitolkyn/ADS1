#include <iostream>
#include <map>
#include <vector>
#define ll long long 
using namespace std;

ll M= 1e9; 
ll P=31; 
const ll size = 1e5;
int arr[size];

ll hashT(string &t){
    ll ht = 0;
    ll p_pow = 1;
    for(int i = 0;i < t.size();i++){
        ll hash = (t[i] - 'a' + 1) * p_pow % M;
        ht = (ht+ hash) % M; 
        p_pow = (p_pow * P) % M;
    }
    return ht;
}

vector<ll> hashS(string &s){
    ll p_pow = 1;
    vector<ll> hs(s.size());
    for(int i = 0;i < s.size();i++){
        hs[i] = (s[i] - 'a' + 1) * p_pow % M; 
        if (i > 0) hs[i] = (hs[i] + hs[i - 1]) % M;
        p_pow = (p_pow*P) % M;
    }
    return hs;
}

bool rabinKarpAlgo(pair<ll,string> p,string &t){
    vector<ll> hs = hashS(t);
    for(int i = 0;i < t.size() - p.second.size()+1;i++){
        ll cur = hs[i + p.second.size() - 1];
        if (i > 0) cur -= hs[i - 1];
        if (cur < 0) cur += M;
        if (i > 0) p.first = (p.first * P) % M; 
        return p.first  == cur;
    }
    return false;
}

string subst(vector<string> &vec){
    string max = "";
    int maxN = 0;
    ll l;
    ll hs1=0;
    ll p_pow1 = 1;
    fill(arr, arr + size, 0);
    for(int i = 0;i < vec[1].size(); i++){
        ll hs = 0;
        hs1 = ((vec[1][i] - 'a' +1)*p_pow1)% M; 
        ll p_pow = 1;
        for(int j = vec[0].size()-1; j >= 0; j--){
            hs = ((vec[0][j] - 'a' + 1) * p_pow)% M;
            if(hs == hs1){
                arr[j + 1] = arr[j] + 1;
            }
            if(arr[j+1] > maxN) {
                maxN = arr[j+1];
                l = j - maxN+1;
            }
        }
    }
    if(maxN==0)return "";
    return vec[0].substr(l, maxN);
}

int main(){
    int n; cin >> n;
    string s;cin >> s;
    for(int i = 0;i < n-1;i++){
        string ss; cin >> ss;
        vector<string> vv;
        vv.push_back(s);
        vv.push_back(ss);
        s = subst(vv);
    }
    cout << s;
    return 0;
}