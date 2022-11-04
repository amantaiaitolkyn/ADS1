#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int> d;
    char x;
    while(x != '!'){
        cin >> x;
        if(x == '+'){
            int num; cin >> num;
            d.push_front(num);
        }
        if(x == '-'){
            int num; cin >> num;
            d.push_back(num);
        }
        if(x == '*'){
            if(d.empty()){
                cout << "error" << endl;
            }else{
                if(d.size() == 1){
                    cout << 2 * d.front() << endl;
                    d.pop_back();
                    continue;
                }else{
                    cout << d.front() + d.back() << endl;
                    d.pop_back();
                    d.pop_front();
                }
            }
        }
    }
    return 0;
}
