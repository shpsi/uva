#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int minOperations(int a[], int n, int k){
    map<int,bool> mp;
    for(int i=0;i<n;++i){
        if(mp.find(a[i]) != mp.end())
            return 0;
        mp[a[i]] = true;
    }
    int b[n];
    for(int i=0;i<n;++i)
        b[i] = a[i] ^ k;
    mp.clear();
    for(int i=0;i<n;++i){
        if(mp.find(b[i]) != mp.end())
            return 2;
        mp[b[i]] = true;
    }
    for(int i=0;i<n;++i){
        if(mp.find(a[i]) != mp.end())
            return 1;
    }
    return -1;
}
int main(){
    int K = 3; 
    int a[] = { 1, 9, 4, 3 }; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    // Function call to compute the result 
    cout << minOperations(a, n, K) << endl;    
    return 0;
}
