#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int minJumps(int a[], int n){
    int fib[30];
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<30;++i)
        fib[i] = fib[i-1]+fib[i-2];
    int dp[n+2];
    memset(dp,INT_MAX,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n+1;++i){
        for(int j=1;j<30;++j){
            if((a[i - 1] == 1 || i == n + 1) && i - fib[j] >= 0)    
                dp[i] = min(dp[i], dp[i-fib[j]]+1);
        }
    }
    if (dp[n + 1] != INT_MAX)
        return dp[n + 1];
    else
        return -1;
}
int main(){
    int arr[] = { 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << minJumps(arr, n) << endl;     
    return 0;
}
