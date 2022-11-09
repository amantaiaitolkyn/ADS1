#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

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

int partition (map<string,string> &m, int low, int high){
    string pivot = m[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++){
        if (checkk(pivot, m[j])){
            i++;
            swap(m[i], m[j]);
        }
    }
    swap(m[i + 1], m[high]);
    return (i + 1);
}


void quickSort(map<string,string> &m, int low, int high)
{
    if (low < high){
        int pi = partition(m, low, high);
        quickSort(m, low, pi - 1);
        quickSort(m, pi + 1, high);
    }
}

int main(){
    map<string,string> m;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        string s,s1; cin >> s >> s1;
        m.insert(s,s1);
    }
    for(int i = 0;i < n;i++){
        if(m[i].second)
    }
    quickSort(m,0,m.size()-1);
    for(int i= 0;i < n;i++){
        // cout << ss[i] << endl;
    }
    return 0;
}