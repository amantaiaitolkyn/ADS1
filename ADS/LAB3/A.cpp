#include <iostream>
using namespace std;
int binSearch(int arr[],int l,int r,int x){
    while(l <= r){
        int m = (l + r)/2;
        if(arr[m] == x){
            return m;
        }
        if(arr[m] > x) r = m - 1;
        if(arr[m] < x) l = m + 1;
    }
    return -1;
}

int binSearchRev(int arr[],int l,int r,int x){
    while(l <= r){
        int m = (l + r)/2;
        if(arr[m] == x){
            return m;
        }
        if(arr[m] > x) l = m + 1;
        if(arr[m] < x) r = m - 1;
    }
    return -1;
}
int main(){
    int n; cin >> n;
    int a[n];

    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    int x,y;
    cin >> x >> y;
    int b[x][y];

    for(int i = 0;i < x;i++){
        for(int j = 0;j < y;j++){
            cin >> b[i][j];
        }
    }

    int ans;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < x;j++){
            if(j % 2 == 0){
                if(b[j][y - 1] > a[i]){
                    continue;
                }else{
                    ans = binSearchRev(b[j],0,y,a[i]);
                    if(ans != -1){
                        cout << j << " " << ans << endl;
                        break;
                    }else{
                        cout << -1 << endl;
                        break;
                    }
                }
            }else{
                if(j == x -1 && b[j][0] > a[i]){
                    cout << -1 << endl;
                    break;
                }
                if(b[j][0] > a[i]){
                    continue;
                }else{
                    ans = binSearch(b[j],0,y,a[i]);
                    if(ans != -1){
                        cout << j << " " << ans << endl;
                        break;
                    }else{
                        cout << -1 << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}