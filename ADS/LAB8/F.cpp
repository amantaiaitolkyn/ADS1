#include<iostream>
#include <unordered_map>
#include <map>
#define ll unsigned long long
using namespace std;
ll M = 1e15+7;
ll P = 31;
int hashS(string s){
    unordered_map<ll,bool> mp;
    for(int i = 0;i < s.size();i++){
        ll p_pow = 1;
        ll hs = 0;
        for(int j = i;j < s.size();j++){
            hs = (hs + ((s[j] - 'a'+1) * p_pow) % M) % M; 
            p_pow = (p_pow*P) % M;
            if(!mp[hs]){
                mp[hs] = true;
            }
        }
    }
    return mp.size();
}

int main(){
    string s; cin >> s;
    cout<<hashS(s);
}