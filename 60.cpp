#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void maxSumArr(int arr[], int n, int k){
    int sum =0 ;
    int ans = INT_MAX;
    int idx;
    for(int i=0;i<k;++i)
        sum += arr[i];
    if(ans>sum){
        ans=sum;
        idx=k;
    }
    for(int i=k;i<n;++i){
        sum = sum - arr[i-k] + arr[i];
        if(ans>sum){
            ans=sum;
            idx=k;
        }
    }
    for (int i = 0; i < idx; i++) 
        cout << arr[i] << " "; 
    for (int i = idx + k; i < n; i++) 
        cout << arr[i] << " "; 
}
int main(){
    int arr[] = { -1, 1, 2, -3, 2, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
  
    maxSumArr(arr, n, k);     
    return 0;
}
