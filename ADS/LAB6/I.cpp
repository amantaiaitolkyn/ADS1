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
    string s; cin >> s;
    vector<char> vec;
    for(int i = 0;i < s.size();i++){
        vec.push_back(s[i]);
    }
    quickSort(vec,0,vec.size()-1);
    for(int i = 0;i < vec.size();i++){
        cout << vec[i];
    }
    return 0;
}

