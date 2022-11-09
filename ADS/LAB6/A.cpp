#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition (vector<char> &vec, int low, int high){
    int pivot = vec[high];
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++){
        if (vec[j] < pivot){
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}


void quickSort(vector<char> &vec, int low, int high)
{
    if (low < high){
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> v;
    vector<char> c;
    for (int i = 0; i < n; i ++){
        char x; cin >> x;
        if(x == 'a'|| x=='e'|| x== 'i' || x== 'o' || x== 'u'){
            v.push_back(x);
        }else{
            c.push_back(x);
        }
    }
    quickSort(v, 0, v.size() - 1);
    quickSort(c, 0, c.size() - 1);
    for (int i = 0; i < v.size(); i++){
        cout << v[i];
    }
    for (int i = 0; i < c.size(); i++){
        cout << c[i];
    }
   return 0;
}