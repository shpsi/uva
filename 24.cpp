#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int xorOdd(int arr[], int n){
    map<int,int> mp;
    for(int i=0;i<n;++i)
        mp[arr[i]]++;
    int ans = 0;
    for(auto it:mp){
        if(it.second%2!=0)
            ans = ans ^ it.first;
    }
    return ans;
}
int main(){
    int arr[] = { 1, 2, 1, 3, 3, 4, 2, 3, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << xorOdd(arr, n) << endl;     
    return 0;
}
