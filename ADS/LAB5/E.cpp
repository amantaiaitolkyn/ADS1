
#include <iostream>
using namespace std;

long long sum = 0;
long long k;
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
        if(size < k){
            size++;
            a[size] = val;
            sift_up(size);
        }else{
            if(a[1] < val){
                a[1] = val;
                sift_down(1);
            }
        }
    }

    void sift_up(int i){
        while(i > 1 && a[parent(i)] > a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    // void sift_down(int i){
    //     int l = left(i);
    //     int r = right(i);
    //     int maxChild = left(i);
    //     if (l > size) return;
    //     if (r <= size){
    //         if (a[r] > a[l]) maxChild = r;
    //     }
    //     if (a[i] < a[maxChild]){
    //         swap(a[i], a[maxChild]);
    //         sift_down(maxChild);
    //     }
    // }

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

    void summ(){
        sum = 0;
        if(size >= k){
            for(long long i = 1;i <= k;i++){
                sum += a[i];
            }
        }else{
            for(long long i = 1;i <= sz();i++){
                sum += a[i];
            }
        }
    }
};
int main(){
    Heap heap;
    long long  q;
    cin >> q >> k;
    for(long long i = 0;i < q;i++){
        string s; cin >> s;
        if(s == "insert"){
            long long x; cin >> x;
            heap.insert(x);
        }
        if(s == "print"){
            if(heap.sz() >= 1){
                heap.summ();
                cout << sum << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }

    return 0;
}