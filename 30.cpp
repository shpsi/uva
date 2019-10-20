#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int divideArray(int arr[], int n, int k){
    int dp[n+1][k+1];
    memset(dp,INT_MAX,sizeof(dp));
    k--;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<=k;++j){
            dp[i][j] = INT_MAX;
            int runningSum = 0;
            int runningMax = INT_MIN;
            for(int l = i; l<n;++l){
                runningSum += arr[l];
                runningMax = max(runningMax, arr[l]);
                int diff = (l - i + 1) * runningMax - runningSum;
                if(j>0)
                    dp[i][j] = min(dp[i][j], diff + dp[l+1][j-1]);
                else
                    dp[i][j] = diff;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=1;j<=k;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][k];
}
int main(){
    int arr[] = { 2, 9, 5, 4, 8, 3, 6 }; 
    int n = sizeof(arr) / sizeof(int); 
    int k = 2; 
  
    cout << divideArray(arr, n, k) << "\n";     
    return 0;
}
