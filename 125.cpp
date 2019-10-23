#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int dp[1000];
int maxSum(int a[], int index, int n, int k){
    if(index>=n)
        return 0;
    if(dp[index] != -1)
        return dp[index];
    int ans=0;
    dp[index] = maxSum(a,index+1,n,k);
    for(int j=index;j<index+k && j<n;++j){
        ans += a[j];
        dp[index] = max(dp[index], ans+maxSum(a,j+1,n,k));
    }
    return dp[index];
}
int main(){
    int arr[] = { -1, 2, -3, 4, 5 }; 
  
    int k = 2; 
  
    int n = sizeof(arr) / sizeof(int); 
    memset(dp,-1,sizeof(dp));
    cout << maxSum(arr, 0, n, k) << endl;    
    return 0;
}
