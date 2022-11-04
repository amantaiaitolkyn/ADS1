#include <iostream>
#include <vector>
using namespace std;

class Heap{
    int a[100005];
    int b[100005];
    int size;
public:
    Heap(){
    a[0] = -2147483647;
    b[0] = -2147483647;
    size = 0;
    }

    int left(int i){
        return i * 2;
    }
    int right(int i){
        return i * 2 + 1;
    }
    int parent(int i){
        return i/2;
    }

    void insert(int val){
        size++;
        a[size] = val;
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        int maxChild = left(i);
        if(l > size){
            return;
        }
        if(r <= size){
            if(a[r] > a[l]) maxChild = r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            sift_down(maxChild);
        }

    }

    int extract_max(){
        int max = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return max;
    }

    void sort(){
        int size1 = size;
        for(int i = 0 ;i < size1;i++){
            int m = extract_max();
            b[i] = m;
        }
        
        for(int i = 1;i <= size1;i++){
            cout << b[size1 - i] << " ";
        }
    }

    void print(){
        for(int i = 1;i <= size;i++){
            cout << a[i] << " ";
        }
    }
};
int main(){
    Heap heap;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        heap.insert(x);
    }
    heap.sort();
    return 0;
}