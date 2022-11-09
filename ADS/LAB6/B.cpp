#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int partition (int a[], int low, int high){
    int pivot = a[high];
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++){
        if (a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}


void quickSort(int a[], int low, int high)
{
    if (low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
int main(){
    int n; int m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < m;i++){
        cin >> b[i];
    }
    quickSort(a,0,n-1);
    quickSort(b,0,m-1);
    if(n > m){
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(b[i] == a[j]){
                    a[j] = 0;
                    cout << b[i] << " ";
                    break;
                }
            }
        }
    }else{
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(a[i] == b[j]){
                    b[j] = 0;
                    cout << a[i] << " ";
                    break;
                }
            }
        }
    }
    
    return 0;
}