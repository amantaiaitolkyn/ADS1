#include <iostream>
#include <vector>
#define ll long long 

using namespace std;

int main(){
    string s1,s2,t;
    cin >> s1 >> s2 >> t;
    vector<ll> ans1;
    vector<ll> ans2;
    vector<ll> p_pow(s1.size());
    vector<ll> hs1(s1.size());
    vector<ll> hs2(s2.size());
    ll p = 5;
    ll ht = 0;

    p_pow[0] = 1; 

    for (int i = 1; i < s1.size(); ++i) {
        p_pow[i] = p_pow[i - 1] * p;
    }

    for (int i = 0; i < t.size(); ++i) {
        ht += (t[i] - 'a' + 1) * p_pow[i]; 
    }


    for (int i = 0; i < s1.size(); ++i) {
        hs1[i] = (s1[i] - 96) * p_pow[i];
        if (i > 0) hs1[i] += hs1[i - 1];
    }
    for (int i = 0; i < s2.size(); ++i) {
        hs2[i] = (s2[i] - 96) * p_pow[i];
        if (i > 0) hs2[i] += hs2[i - 1];
    }

    for (int i = 0; i + t.size() - 1 < s1.size(); i++) {
        ll cur = hs1[i + t.size() - 1];
        if (i > 0) cur -= hs1[i - 1];
        if (ht * p_pow[i] == cur) ans1.push_back(i);
    }
    for (int i = 0; i + t.size() - 1 < s2.size(); i++) {
        ll cur = hs2[i + t.size() - 1];
        if (i > 0) cur -= hs2[i - 1];
        if (ht * p_pow[i] == cur) ans2.push_back(i);
    }
    ll cnt = 0;
    for(int i = 0;i < ans1.size();i++){
        for(int j = 0;j < ans2.size();j++){
            if(ans1[i] == ans2[j]){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
