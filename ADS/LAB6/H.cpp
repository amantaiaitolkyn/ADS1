#include <iostream>
#include <cmath>
#include <vector>
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
int main(){
    int n; cin >> n;
    vector<char> v;
    for(int i = 0;i < n;i++){
        char x; cin >> x;
        v.push_back(x);
    }
    char c; cin >> c;
    quickSort(v,0,v.size()-1);
    int cnt = 0;
    for(int i = 0;i < v.size();i++){
        if(v[i] > c){ 
            cout << v[i];
            cnt++;
            break;
        }
    }
    if(cnt == 0){
        cout << v[0];
    }
    return 0;
}