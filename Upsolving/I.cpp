#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n; cin >> n;
    for(int i = 0;i <n;i++){
        long long int x; cin >> x;
        if(x == 0){
            cout << "NO";
        }else{
            stack<int> s;
            int j = 0;
            int a[10000];
            while(x > 0){
                int num = x % 2;
                a[j] = num;
                x = x / 2;
                j++;
            }
        
            for(int i =0 ;i < j;i++){
                if(s.empty()){
                    s.push(a[j-i-1]);
                }else{
                    if(s.top() == 1 && a[j-i-1] == 0){
                        s.pop();
                    }else{
                        s.push(a[j-i-1]);
                    }
                }
            }

            if(s.empty()){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
        
    }
    return 0;
}