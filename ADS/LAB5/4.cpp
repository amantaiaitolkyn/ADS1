#include <iostream>
using namespace std;
class Heap{
    int a[100005];
    int size;
public:
    Heap(){
        size =0;
        a[0] = -2147483647;
    }
    int parent(int i){
        return i/2;
    }
    void push(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }
    void sift_up(int i){
        while(i > 1 && a[i] > a[parent(i)]){
            swap(a[i],a[parent(i)]);
            i = parent(i);
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
    for(int i=0;i < n;i++){
        int x; cin >> x;
        heap.push(x);
    }
    heap.print();
    return 0;
}