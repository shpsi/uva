#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int findCnt(int a[], int n, int k){
    int ans=0;
    for(int i=1;i<n;++i){
        a[i] += a[i-1];
        if(a[i]>k || a[i]<-1*k)
            ans++;
    }
    if (a[0] > k || a[0] < -1 * k)
        ans++;
    sort(a,a+n);
    for(int i=0;i<n;++i)
        ans += n - (upper_bound(a,a+n,a[i]+k)-a);
    return ans;
}
int main(){
    int arr[] = { -1, 4, -5, 6 }; 
    int n = sizeof(arr) / sizeof(int); 
    int k = 0; 
  
    // Function to find required value 
    cout << findCnt(arr, n, k)<<endl;    
    return 0;
}
