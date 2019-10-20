#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int largestSubArr(int arr[], int n){
    int inc[n], dec[n];
    memset(inc,0,sizeof(inc));
    memset(dec,0,sizeof(dec));
    inc[0] = 1;
    dec[n-1] = 1;
    for(int i=1;i<n;++i){
        if(arr[i]>arr[i-1])
            inc[i] = inc[i-1] + 1;
        else
            inc[i] = 1;
    }
    for(int i=n-2;i>=0;--i){
        if(arr[i]>arr[i+1])
            dec[i] = dec[i+1] + 1;
        else
            dec[i] = 1;
    }
    int maxSubArr = INT_MIN;
    for(int i=0;i<n;++i)
        maxSubArr = max(maxSubArr,inc[i]+dec[i]-1);
    return maxSubArr;
}
int main(){
    int arr[] = { 1, 2, 2, 1, 3 }; 
    int n = sizeof(arr) / sizeof(int); 
  
    cout << largestSubArr(arr, n) << endl;     
    return 0;
}
