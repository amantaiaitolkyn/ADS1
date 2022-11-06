#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n; cin >> n;
    for(int i = 0;i <n;i++){
        long long int x; cin >> x;
        stack<char> st;
        string ss;
        while(x){
            int  num = x % 2;
            x = x/2;
            ss += (num+'0');
        }
        int j = ss.size();
        for(int k = 0 ;k < j;k++){
            if(st.empty()){
                st.push(ss[k]);
            }else{
                if(st.top() == '0' && ss[k] == '1'){
                    st.pop();
                }else{
                    st.push(ss[k]);
                }
            }
        }

        if(st.empty()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}