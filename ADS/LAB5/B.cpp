#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Heap{
    int a[100005];
    int size;
public:
    Heap(){
    a[0] = -2147483647;
    size = 0;
    }

    int left(int  i){
        return i * 2;
    }
    int right(int i){
        return i * 2 + 1;
    }
    int  parent(int i){
        return i/2;
    }

    int sz(){
        return size;
    }

    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size);

    }

    void sift_up(int i){
        while(i > 1 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        int maxChild = left(i);
        if (l > size) return;
        if (r <= size){
            if (a[r] > a[l]) maxChild = r;
        }
        if (a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            sift_down(maxChild);
        }
    }

    int extract_max(){
        int ans = a[1];
        if (size >= 1) { 
            swap(a[1], a[size]);
            size--;
        }
        sift_down(1);
        return ans;
    }

    void print(){
        if (size) cout << a[1];
        else cout << 0 ;
    }
};
int main(){
    Heap heap;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        heap.insert(x);
    }
    while(heap.sz() > 1){
        int x,y;
        x = heap.extract_max();
        y = heap.extract_max();
        int ans = x - y;
        if (ans >  0) heap.insert(ans);
        
    }
    heap.print();

    return 0;
}