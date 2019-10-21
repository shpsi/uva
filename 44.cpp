#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int minCost(int arr[], int cost[], int n){
    int ans = 100000;
    for(int j=0;j<n;++j){
        int lc,rc;
        lc =100000;
        rc=lc;
        for(int i=0;i<j;++i){
            if(arr[i]<arr[j]){
                lc = min(lc,cost[i]);
            }
        }
        for(int k=j+1;k<n;++k){
            if(arr[k]>arr[j]){
                rc =min(rc,cost[k]);
            }
        }
        ans = min(ans, lc + cost[j] + rc);
    }
    if(ans>100000)
        return -1;
    return ans;
}
int main(){
    int arr[] = { 2, 4, 5, 4, 10 }; 
    int cost[] = { 40, 30, 20, 10, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << minCost(arr, cost, n) << endl;     
    return 0;
}
