#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<char> st;
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(st.empty()){
            st.push(s[i]);
        }else{
            if(s[i] == st.top()){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
    }
    if(st.empty()){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}