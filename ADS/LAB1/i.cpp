#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int> kk;
    deque<int> ss;
    int n; cin >> n;
    string s; cin >> s;
    for(int i =0;i < n;i++){
        if(s[i] == 'S'){
            ss.push_back(i);
        }else{
            kk.push_back(i);
        }
    }
    while(!kk.empty() and !ss.empty()){
        int a = kk.front();
        int b = ss.front();
        if(a < b){
            kk.push_back(a + s.size());
            kk.pop_front();
            ss.pop_front();
        }else{
            ss.push_back(b + s.size());
            kk.pop_front();
            ss.pop_front();
        }
    }
    if(kk.empty()){
        cout << "SAKAYANAGI";
    }else{
        cout << "KATSURAGI";
    }
    return 0;
}
