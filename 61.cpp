#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int mod = 1e9 + 7;
int ways(int arr[], int n){
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[n-1] = 1;
    for(int i=n-2;i>=0;--i){
        int ans=0;
        for(int j=1;j+i<n && j<=arr[i];++j)
            ans += dp[i+j];
        dp[i] = ans;
    }
    return dp[0];
}
int main(){
    int arr[] = { 5, 3, 1, 4, 3 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << ways(arr, n) % mod << endl; 
    return 0;
}
