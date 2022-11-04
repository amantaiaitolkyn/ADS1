#include <iostream>
using namespace std;
long long money;
int x;
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

    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    void sift_up(int i){
        while(i > 1 and a[i] > a[parent(i)]){
            swap(a[i],a[parent(i)]);
            i = parent(i);
        }
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        int maxChild = l;
        if(l > size) return;
        if(r <= size){
            if(a[r] > a[l]) maxChild = r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i],a[maxChild]);
            sift_down(maxChild);
        }

    }

    void check(){
        for(int i = 0;i < x;i++){
            money += a[1];
            a[1] -= 1;
            sift_down(1);
        }
    }

};
int main(){
    Heap heap;
    int n;
    cin >> n >> x;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        heap.insert(x);
    }
    heap.check();
    cout << money;
    return 0;
}