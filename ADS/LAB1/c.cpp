#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<char> ans1;
    deque<char> ans2;
    string s1,s2;
    cin >> s1 >> s2;
    for(int i = 0;i < s1.size();i++){
        if(ans1.empty()){
            if(s1[i] >= 'a' and s1[i] <= 'z'){
                ans1.push_back(s1[i]);
            }
        }else{
            if(s1[i] == '#'){
                ans1.pop_back();
            }else{
                ans1.push_back(s1[i]);
            }
        }
    }
    for(int i = 0;i < s2.size();i++){
        if(ans2.empty()){
            if(s2[i] >= 'a' and s2[i] <= 'z'){
                ans2.push_back(s2[i]);
            }
        }else{
            if(s2[i] == '#'){
                ans2.pop_back();
            }else{
                ans2.push_back(s2[i]);
            }
        }
    }
    if(ans1.size() == ans2.size()){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}