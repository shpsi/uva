#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int LongestSubarray(int a[], int n, int k){
    int pre[n];
    for(int i=0;i<n;++i){
        if(a[i]>k)
            pre[i] = 1;
        else
            pre[i] = -1;
    }
    for(int i=1;i<n;++i)
        pre[i] = a[i] + pre[i-1];
    int ans = 0;
    int lo = 0;
    int hi = n-1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        bool ok = false;
        for(int i=mid-1;i<n;++i){
            if(pre[i] - pre[i-mid+1]>0){
                ok = true;
                break;
            }
        }
        if(ok){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return ans;
}
int main(){
    int a[] = { 2, 3, 4, 5, 3, 7 }; 
    int k = 3; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    cout << LongestSubarray(a, n, k) << endl;     
    return 0;
}
