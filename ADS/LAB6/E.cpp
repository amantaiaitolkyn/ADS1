
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int a[1005][1005];
int partition (int row, int low, int high){
    int pivot = a[high][row];
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++){
        if (a[j][row] > pivot){
            i++;
            swap(a[i][row], a[j][row]);
        }
    }
    swap(a[i + 1][row], a[high][row]);
    return (i + 1);
}


void quickSort(int row, int low, int high)
{
    if (low < high){
        int pi = partition(row, low, high);
        quickSort(row, low, pi - 1);
        quickSort(row, pi + 1, high);
    }
}
int main(){
    int n,m; 
    cin >>n>>m;
    for(int i =0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0;i< m;i++){
        quickSort(i,0,n);
    }

    for(int i = 0;i< n;i++){
        for(int j = 0;j < m;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}