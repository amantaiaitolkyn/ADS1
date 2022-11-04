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
    int left(int i){
        return i*2;
    }
    int right(int i){
        return i*2+1;
    }
    void push(int val){
        size++;
        a[size] =val;
        sift_up(size);
    }
    void sift_up(int i){
        while(i > 1 && a[i] > a[parent(i)]){
            swap(a[i],a[parent(i)]);
            i = parent(i);
        }
    }
    void extract_max(){
        int max = a[1];
        swap(a[size],a[1]);
        size--;
        sift_down(1);
        cout << max << endl;
    }
    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        int maxChild = l;
        if(l > size){
            cout << i << " ";
            return;
        }
        if(r <= size){
            if(a[r] > a[l]) maxChild =r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i],a[maxChild]);
            sift_down(maxChild);
        }else{
            cout << i << " ";
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
    for(int i = 0;i < n-1;i++){
        heap.extract_max();
    }
    return 0;
}