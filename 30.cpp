#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int divideArray(int arr[], int n, int k){
    int dp[n+1][k+1];
    memset(dp,INT_MAX,sizeof(dp));
    int prefixSum = 0, preMax=INT_MIN;
    for(int i=0;i<n;++i){
        prefixSum += arr[i];
        preMax=max(preMax,arr[i]);
        dp[i][0] = preMax*(i)-prefixSum;
    }
    for(int i=1;i<n;++i){
        for(int part=1;part<=k;++part){
            int runningSum = arr[i];
            int runningMax = arr[i];
            for(int j =i-1; j>=0;--j){
                runningSum += arr[j];
                runningMax = max(runningMax,arr[j]);
                //cerr<<"debug:: "<<i<<" "<<j<<" "<<part<<" "<<runningSum<<" "<<runningMax<<endl;
                dp[i][part] = min(dp[i][part], runningMax*(i-j+1)-runningSum+dp[j][part-1]);
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=1;j<=k;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n-1][k];
}
int main(){
    int arr[] = { 2, 9, 5, 4, 8, 3, 6 }; 
    int n = sizeof(arr) / sizeof(int); 
    int k = 2; 
  
    cout << divideArray(arr, n, k) << "\n";     
    return 0;
}
