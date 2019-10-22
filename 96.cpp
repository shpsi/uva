#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define MAX 1000
int maximizeSum(int a[], int n, int currIdx, int k, int dp[MAX][MAX]){
    if(k==0){
        if(currIdx == n)
            return 0;
        return INT_MIN;
    }
    if(currIdx == n)
        return INT_MIN;
    if(dp[currIdx][k] != -1)
        return dp[currIdx][k];
    int ans = 0;
    int minNow = INT_MAX;
    for(int i=currIdx;i<n;++i){
        minNow = min(minNow, a[i]);
        ans = max(ans, maximizeSum(a,n,i+1,k-1,dp) + minNow);
    }
    return dp[currIdx][k] = ans;
}
int main(){
    int a[] = { 5, 7, 4, 2, 8, 1, 6 }; 
    int k = 3; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    // Initialize dp array with -1 
    int dp[MAX][MAX]; 
    memset(dp, -1, sizeof dp); 
  
    cout << maximizeSum(a, n, 0, k, dp) << endl;    
    return 0;
}
