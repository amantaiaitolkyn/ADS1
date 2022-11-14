#include <iostream> 
 
using namespace std; 
 
const int t = 256; 
const long long w = 1000000005721; 
 
int RKA(string text, string pattern){ 
 
    int tlen = text.length(); 
    int plen = pattern.length(); 
 
    int flag; 
    int c=1,i=0; 
    int cnt = 0; 
     
    int hash_p=0,hash=0; 
    while(i<plen){ 
        hash_p=(hash_p*t + pattern[i])%w; 
        hash=(hash*t + text[i])%w; 
        i++; 
    } 
     
    for(int i=1;i<=plen-1;i++) 
        c=(c*t)%w; 
     
    i=0; 
    while(i<=tlen-plen){ 
       if(hash_p==hash){ 
            flag=1; 
            for(int j=0;j<plen;j++){ 
                if(pattern[j]==text[i+j]){ 
                    continue; 
                } 
                else{ 
                    flag = 0; break; 
                } 
           } 
            if(flag==1) return 1; 
       } 
 
       if(i<tlen-plen){ 
           hash=((t*(hash-text[i]*c))+text[i+plen])%w; 
            if(hash<0){ 
                hash = hash + w; 
            } 
       } 
       i++; 
    } 
return 0; 
} 
 
int main(){ 
    int n; cin >> n; 
    string array[n-1]; 
    string first_str; cin >> first_str; 
    for (int i = 0; i < n-1; i++) 
        cin >> array[i]; 
 
    int y = 1; 
    string lcs=""; 
    while(!first_str.empty()) 
    { 
        string pattern = first_str.substr(0,y); 
        int cnt=0; 
        for (int j = 0; j < n-1; j++) 
            cnt = cnt + RKA(array[j], pattern); 
         
        if(y>=first_str.size()) 
            break; 
 
        if(n-1==cnt){ 
            y++; 
            if(lcs.size()<pattern.size()) 
                lcs = pattern; 
        } 
        else{ 
            first_str.erase(first_str.begin(),first_str.begin()+1); 
            y=1; 
        } 
    } 
     
    cout << lcs << endl; 
}