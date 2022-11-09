#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int partition(int a[],int low,int high){
    int pivot = a[high];
    int i = (low-1);
    for(int j = low;j <= high-1;j++){
        if(a[j] < pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return (i+1);
}

void quickSort(int a[],int low,int high){
    if(low < high){
        int pi = partition(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}
int main(){
    int n; cin >> n;
    int a[n];
    int b[n];
    for(int i = 0;i <n;i++){
        cin >> a[i];
        b[i] = a[i];
    }

    int min = abs(a[0] - a[1]);
    quickSort(a,0,n-1);
    for(int i = 0;i < n;i++){
        if(abs(a[i] - a[i-1]) < min){
            min = abs(a[i] - a[i-1]);
        }
    }
    vector<pair< int, int > > check;
    for(int i = 0;i < n;i++){
        if(abs(a[i] - a[i+1]) == min){
            check.push_back(make_pair(a[i],a[i+1]));
        }
    }
    for(int i = 0;i < check.size();i++){
        cout << check[i].first << " " << check[i].second << " ";
    }
    
    return 0;
}