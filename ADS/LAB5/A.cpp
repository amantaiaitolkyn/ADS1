#include <iostream>
using namespace std;

class Heap{
    long long a[100005];
    long long size;
public:
    Heap(){
    a[0] = -2147483647;
    size = 0;
    }

    long long left(long long  i){
        return i * 2;
    }
    long long right(long long i){
        return i * 2 + 1;
    }
    long long  parent(long long i){
        return i/2;
    }

    int sz(){
        return size;
    }

    void insert(long long val){
        size++;
        a[size] = val;
        sift_up(size);

    }

    void sift_up(int i){
        while(i > 1 && a[parent(i)] > a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        int minChild = left(i);
        if(l > size){
            return;
        }
        if(r <= size){
            if(a[r] < a[l]) minChild = r;
        }
        if(a[i] > a[minChild]){
            swap(a[i], a[minChild]);
            sift_down(minChild);
        }

    }

    void extract_max(){
        long long max = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        cout << max << endl;
    }

    long long  extract_min(){
        long min = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return min;
    }

    void print(){
        for(long long i = 1;i <= size;i++){
            cout << a[i] << " ";
        }
    }
};
int main(){
    Heap heap;
    long long n; cin >> n;
    for(long long i = 0;i < n;i++){
        long long x; cin >> x;
        heap.insert(x);
    }
    long long a,b;
    long long ans;
    while(heap.sz() > 1){
        a = heap.extract_min();
        b = heap.extract_min();
        ans += a + b;
        heap.insert(a + b);
    }
    cout << ans;

    return 0;
}