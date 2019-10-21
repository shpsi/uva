#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
pair<int, int> countSum(int a[], int n){
    int odd ,even;
    odd = 0;
    even = 0;
    for(int i=0;i<n;++i)
        if(a[i]%2)
            odd++;
        else
            even++;
    int os = (1 << even) * (1 << (odd - 1)); 
    int es = (1 << n) - 1 - os;
    return make_pair(es,os);
}
int main(){
    int arr[] = { 1, 2, 2, 3 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Calling the function 
    pair<int, int> ans = countSum(arr, n); 
  
    cout << "EvenSum = " << ans.first; 
    cout << " OddSum = " << ans.second;     
    return 0;
}
