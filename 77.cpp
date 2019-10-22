#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int Min_Replace(int a[], int n, int k){
    sort(a,a+n);
    int mpc=0;
    int freq[100];
    memset(freq,0,sizeof(freq));
    freq[mpc]=1;
    for(int i=1;i<n;++i){
        if(a[i] == a[i-1])
            freq[mpc]++;
        else{
            mpc++;
            freq[mpc]++;
        }
    }
    sort(freq, freq+n, greater<int>());
    int ans=0;
    for(int i=k;i<=mpc;++i){
        ans += freq[i];
    }
    return ans;
}
int main(){
    int arr[] = { 1, 2, 7, 8, 2, 3, 2, 3 }; 
      
    int n = sizeof(arr) / sizeof(arr[0]); 
      
    int k = 2; 
      
    cout << Min_Replace(arr, n, k) << endl;    
    return 0;
}
