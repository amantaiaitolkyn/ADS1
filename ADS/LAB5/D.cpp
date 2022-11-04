#include <iostream>
using namespace std;
int m;
int n;
int cnt = 0;
class Heap{
    long long a[1000005];
    long long size;
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

    long long extract_min(){
        int min = a[1];
        swap(a[1],a[size]);
        size--;
        sift_down(1);
        return min;
    }

    void mixtures(){
        int d;
        while(a[1] < m){
            cnt++;
            int min1 = extract_min();
            int min2 = extract_min();
            d = min1 + 2*min2;
            insert(d);
        }
        if (cnt >= n) {
            cout << -1;
        }else{
            cout << cnt;
        }
    }
};
int main(){
    Heap heap;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        heap.insert(x);
    }
    heap.mixtures();
    return 0;
}