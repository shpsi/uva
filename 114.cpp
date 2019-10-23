#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int max_sum(int a[], int n){
    int dp[n]; 
  
    // If there is a single element in the array 
    if (n == 1) { 
  
        // Either select it or don't 
        dp[0] = max(0, a[0]); 
    } 
  
    // If there are two elements 
    else if (n == 2) { 
  
        // Either select the first 
        // element or don't 
        dp[0] = max(0, a[0]); 
  
        // Either select the first or the second element 
        // or don't select any element 
        dp[1] = max(a[1], dp[0]); 
    }
    else if(n>=3){
        dp[0] = max(0, a[0]);
        dp[1] = max(0, max(a[0], 0));
        dp[2] = max(a[2], max(a[1], max(0,a[0])));
        for(int i=3;i<n;++i){
            dp[i] = max(dp[i-1] , a[i] + dp[i-3]);
        }
    }
    return dp[n-1];
}
int main(){
    int arr[] = { 1, 2, -2, 4, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << max_sum(arr, n) << endl;    
    return 0;
}
