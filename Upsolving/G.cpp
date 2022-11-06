#include  <iostream>
#include <queue>
#include <deque>
using namespace std;
int main(){
    queue<int> s;
    deque<int> d;
    int n; cin >> n;
    for(int i = 1;i <= n;i++){
        int x; cin >> x;
        if(x <= 3000){
            d.push_back(x);
            s.push(i);
        }else{
            int i = d.size();
            while(d.front() < x - 3000){
                d.pop_front();
                s.push(i);

            }
        }
    }
    while(!s.empty()){
        int val = s.front();
        s.pop();
        cout << val << " ";
    }
    return 0;
}
