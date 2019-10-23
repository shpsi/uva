#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void print_in_order(int a[], int b[], int n, int m){
    map<int,int> mp;
    map<int,int>::iterator itr;
    for(int i=0;i<n;++i)
        mp[a[i]]++;
    for(int i=0;i<m;++i){
        if (mp.find(b[i]) != mp.end()) { 
            itr = mp.find(b[i]); 
            for (int j = 0; j < itr->second; j++) 
                cout << itr->first << " "; 
            mp.erase(b[i]); 
        } 
    } 
    for (itr = mp.begin(); itr != mp.end(); itr++) { 
        for (int j = 0; j < itr->second; j++) 
            cout << itr->first << " "; 
    } 
    cout << endl;
}
int main(){
    int a1[] = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 }; 
    int a2[] = { 2, 1, 8, 3 }; 
    int n = sizeof(a1) / sizeof(a1[0]); 
    int m = sizeof(a2) / sizeof(a2[0]); 
  
    print_in_order(a1, a2, n, m);    
    return 0;
}
