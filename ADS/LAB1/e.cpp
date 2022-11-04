#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int> q1;
    deque<int> q2;
    for(int i = 0;i < 5;i++){
        int x; cin >> x;
        q1.push_back(x);
    }
    for(int i = 0;i < 5;i++){
        int x; cin >> x;
        q2.push_back(x);
    }
    int cnt = 0;
    while(!q1.empty() and !q2.empty() and cnt < 1000000){
        int num1 = q1.front();
        int num2 = q2.front();
        cnt++;
        q1.pop_front();
        q2.pop_front();
        if(num1 == 0 and num2 == 9){
            q1.push_back(num1);
            q1.push_back(num2);
        }else if(num1 == 9 and num2 == 0){
            q2.push_back(num1);
            q2.push_back(num2);
        }else if(num1 > num2){
            q1.push_back(num1);
            q1.push_back(num2);
        }else{
            q2.push_back(num1);
            q2.push_back(num2);
        }
    }
    if(q1.empty()){
        cout << "Nursik " << cnt;
    }else if(q2.empty()){
        cout << "Boris " << cnt;
    }else{
        cout << "blin nichya";
    }
    return 0;

}