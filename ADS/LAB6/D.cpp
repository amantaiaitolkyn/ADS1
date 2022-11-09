#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool checkk(string &s1,string &s2){
    if(stoi(s1.substr(6,4)) > stoi(s2.substr(6,4))){
        return true;
    }
    if(stoi(s1.substr(6,4)) < stoi(s2.substr(6,4))){
        return false;
    }
    if(stoi(s1.substr(3,2)) > stoi(s2.substr(3,2))){
        return true;
    }
    if(stoi(s1.substr(3,2)) < stoi(s2.substr(3,2))){
        return false;
    }
    if(stoi(s1.substr(0,2)) > stoi(s2.substr(0,2))){
        return true;
    }
    if(stoi(s1.substr(0,2)) < stoi(s2.substr(0,2))){
        return false;
    }
    return false;

}

int partition (vector<string> &vec, int low, int high){
    string pivot = vec[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++){
        if (checkk(pivot, vec[j])){
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}


void quickSort(vector<string> &vec, int low, int high)
{
    if (low < high){
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main(){
    vector<string> ss;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        string s; cin >> s;
        ss.push_back(s);
    }
    quickSort(ss,0,ss.size()-1);
    for(int i= 0;i < n;i++){
        cout << ss[i] << endl;
    }
    return 0;
}