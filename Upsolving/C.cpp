#include <iostream>
using namespace std;
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
    void push(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    int sift_up(int i){
        while(i > 1 && a[parent(i)] < a[i]){
            swap(a[i] , a[parent(i)]);
            i = parent(i);
        }
        return i;
    }

    void increase(int pos,int val){
        a[pos] += val;
        cout << sift_up(pos) << endl;
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
        heap.push(x);
    }
    int q; cin >> q;
    for(int i = 0;i < q;i++){
        int pos,val; cin >> pos >> val;
        heap.increase(pos,val);
    }
    heap.print();
    return 0;
}