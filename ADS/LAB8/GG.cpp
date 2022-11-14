#include <iostream>
#include <map>
#include <vector>
#define ll long long 
using namespace std;

ll M = 1e9 + 9;
ll P = 31;

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

void rabinKarpAlgo(string &s,pair<string,int> &p,vector<ll> &hs){
    if(p.first.size() > s.size()){
        return;
    }
    ll ht = hashT(p.first);
    for(int i = 0;i < s.size() - p.first.size()+1;i++){
        ll cur = hs[i + p.first.size() - 1];
        if (i > 0) cur -= hs[i - 1];
        if (cur < 0) cur += M;
        if (i > 0) ht = (ht * P) % M; 
        if (ht  == cur){
            p.second++;
        }
    }
}
int main(){
    string s; cin >> s;
    vector<ll> hashh = hashS(s);
    int x; cin >> x;
    pair<string,int> p[x];
    for(int i = 0;i < x;i++){
        int n1,n2;
        cin >> n1 >> n2;
        string t = "";
        for(int j = n1-1;j < n2;j++){
            t+=s[j];
        }
        p[i].first = t;
        p[i].second = 0;
    }
    for(int i = 0;i < x;i++){
        rabinKarpAlgo(s,p[i],hashh);
    }
    for(int i = 0;i < x;i++){
        cout << p[i].second << endl;
    }
}