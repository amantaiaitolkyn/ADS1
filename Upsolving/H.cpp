#include <iostream>
using namespace std;
int cnt =0;
class Heap{
    int a[100005];
    int size;
public:
    Heap(){
        a[0] = -2147483647;
        size = 0;
    }
    int parent(int i){
        return i/2;
    }
    int left(int i){
        return i*2;
    }
    int right(int i){
        return i*2+1;
    }
    void push(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    void sift_up(int i){
        while(i > 1 && a[parent(i)] < a[i]){
            swap(a[i] , a[parent(i)]);
            i = parent(i);
        }
    }

    void check(){
        for(int i = 1;i <= size/2;i++){
            int l = left(i);
            int r = right(i);
            if(r <= size){
                if(a[r] > a[l]){
                    cnt++;
                }
            }
        }
    }
};
int main(){
    Heap heap;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        heap.push(x);
    }
    heap.check();
    cout << cnt;
    return 0;
}