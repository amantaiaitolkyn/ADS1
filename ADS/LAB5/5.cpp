#include <iostream>
using namespace std;
class Heap{
    int a[100005];
    int size;
public:
    Heap(){
        a[0]=-2147483647;
        size = 0;
    }
    int parent(int i){
        return i / 2;
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
    }
    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        int maxChild = l;
        if(l > size) return;
        if(r <= size){
            if(a[r] > a[l]) maxChild =r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i],a[maxChild]);
            sift_down(maxChild);
        }
    }
    void bulid_heap(){
        for(int i = size/2;i >= 1;i--){
            sift_down(i);
        }
    }
    void print(){
        for(int i=1;i <= size;i++){
            cout << a[i] << " ";
        }
    }
};
int main(){
    Heap heap;
    int n; cin >> n;
    for(int i =0;i < n;i++){
        int x; cin >> x;
        heap.push(x);
    }
    heap.bulid_heap();
    heap.print();
    return 0;
}