#include <iostream>
#include <vector>
using namespace std;
struct Stack{
    vector<int> vec;
    void push(int x){
        vec.push_back(x);
    }
    void pop(){
        vec.pop_back();
    }
    void  getcur(){
        if(vec.size()== 0){
            cout << "error" << endl;
        }else{
           cout << vec[vec.size()-1]<< endl;
        }
    }

    void getmax(){
        if(vec.size() == 0){
            cout << "error" << endl;
        }else{
            long long max = -1e9;
            for(int i = 0;i < vec.size();i++){
                if(vec[i] > max){
                    max = vec[i];
                }
            }
            cout << max << endl;
        }
    }
};
int main(){
    Stack stack;
    int q; cin >>q;
    for(int i = 0;i < q;i++){
        string s; cin >> s;
        if(s == "add"){
            int x; cin >> x;
            stack.push(x);
        }else if(s == "delete"){
            stack.pop();
        }else if(s == "getcur"){
            stack.getcur();
        }else if(s == "getmax"){
            stack.getmax();
        }
    }
    return 0;
}