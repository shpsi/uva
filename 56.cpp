#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int kadane(int a[], int idx, int n, int k){
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    for(int i=idx;i<n;i+=k){
        maxEndingHere = maxEndingHere + a[i];
        maxSoFar = max(maxSoFar, maxEndingHere);
        maxEndingHere = max(0, maxEndingHere);
    }
    return maxSoFar;
}
int find(int a[], int n, int k){
    int ans = INT_MIN;
    for(int i=0;i<=min(n,k);++i){
        ans = max(ans, kadane(a,i,n,k));
    }
    return ans;
}
int main(){
    int arr[] = { 2, -3, -1, -1, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 2; 
  
    cout << find(arr, n, k);     
    return 0;
}
