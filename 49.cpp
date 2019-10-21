#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void farthest_min(int arr[], int n){
    int suffixMin[n];
    memset(suffixMin,INT_MAX,n);
    suffixMin[n-1] = arr[n-1];
    for(int i=n-2;i>=0;--i)
        suffixMin[i] = min(arr[i], suffixMin[i+1]);
    for(int i=0;i<n;++i){
        int low, high, ans = INT_MIN;
        low = i+1;
        high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(suffixMin[mid] < arr[i]){
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        cout << ans <<" ";
    }
    cout<<endl;
}
int main(){
    int a[] = { 3, 1, 5, 2, 4 }; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    farthest_min(a, n);     
    return 0;
}
