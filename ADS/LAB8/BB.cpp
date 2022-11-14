#include <iostream>
#include <map>
#include <vector>
#define ll long long 
using namespace std;

ll M = 1e9 + 7;
ll P = 31;
map<int,int> m;
int cnt = 0;

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

void rabinKarpAlgo(string &s,string &t){
    if(t.size() >s.size()){
        return;
    }
    ll ht = hashT(t);
    vector<ll> hs = hashS(s);
    for(int i = 0;i < s.size() - t.size()+1;i++){
        ll cur = hs[i + t.size() - 1];
        if (i > 0) cur -= hs[i - 1];
        if (cur < 0) cur += M;
        if (i > 0) ht = (ht * P) % M; 
        if (ht  == cur){
            if(m.find(i) != m.end()){
                cnt++;
            }
            m[i] = 1;
        }
    }
}
int main(){
    string s1,s2,t;
    cin >> s1 >> s2 >> t;
    rabinKarpAlgo(s1,t);
    rabinKarpAlgo(s2,t);
    cout << cnt;
    return 0;
}