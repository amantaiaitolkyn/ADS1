#include <iostream>
#include <map>
#include <vector>
#define ll long long 
using namespace std;

ll M = 1e9 + 7;
ll P = 11;

string hashS(string s){
    ll p_pow = 1;
    ll hs = 0;
    for(int i = 0;i < s.size();i++){
        hs = (hs + ((s[i] - 47) * p_pow) % M) % M; 
        p_pow = (p_pow*P) % M;
    }
    return to_string(hs);
}

int main(){
    int n; cin >> n;
    vector<string> v;
    map<string,string> mp;
    for(int i = 0;i < 2 * n;i++){
        string s;
        cin >> s;
        v.push_back(s);
        mp[s] = hashS(s);
    }
    int n1 = 0;
    for(int i = 0;i < v.size();i++){
        if(mp.find(hashS(v[i]))!= mp.end()){
            cout << "Hash of string " << "\"" << v[i] << "\"" << " is " << hashS(v[i]) << endl;
            n1++;
        }
        if(n1 == n){
            break;
        }
    }
    return 0;
}