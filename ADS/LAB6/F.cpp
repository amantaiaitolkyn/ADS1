#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

bool checkk(vector<pair<pair<string,string>,double > > &vec1,vector<pair<pair<string,string>,double > > &vec2){
    if(vec1.second > vec2.second){
        return true;
    }

}

int partition (vector<pair<pair<string,string>,double > > &vec, int low, int high){
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


void quickSort(vector<pair<pair<string,string>,double > > &vec, int low, int high)
{
    if (low < high){
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main(){
    vector<pair<pair<string,string>,double> > v;
    int n; cin >> n;
    map<string,double> m;
    m.insert(make_pair("A",3.75));
    m.insert(make_pair("B+",3.50));
    m.insert(make_pair("B",3.00));
    m.insert(make_pair("C+",2.50));
    m.insert(make_pair("C",2.00));
    m.insert(make_pair("D+",1.50));
    m.insert(make_pair("D",1.00));
    m.insert(make_pair("F",0));

    for(int i = 0;i < n;i++){
        string name,surname; cin >> name >> surname;
        int x; cin >> x;
        int avg = 0;
        for(int j = 0;j < x;j++){
            string mark; int c; cin >> mark >> c;
            avg += (m[mark]*c/c);
        }
        v[i].first.first = name;
        v[i].first.second = surname;
        v[i].second = avg;
    }
    return 0;
}