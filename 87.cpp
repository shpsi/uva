#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int Max_Sum(int a[], int b[], int n){
    int dp[n][2];
    memset(dp,-1,sizeof(dp));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    for(int i=1;i<n;++i){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+a[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+b[i]);
    }
    return max(dp[n-1][0], dp[n-1][1]);
}
int main(){
    int arr1[] = {9, 3, 5, 7, 3}; 
    int arr2[] = {5, 8, 1, 4, 5}; 
  
    int n = sizeof(arr1) / sizeof(arr1[0]); 
      
    // Function call 
    cout << Max_Sum(arr1, arr2, n) << endl;    
    return 0;
}
