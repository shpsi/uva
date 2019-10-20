#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int countOp(int arr[], int n, int k){
    int ans = 0;
    for(int i=1;i<n;++i){
        if(abs(arr[i]-arr[i-1])>k){
            int absDiff = abs(arr[i]-arr[i-1]);
            int currExtra = absDiff - k;
            if(arr[i] < arr[i-1])
                arr[i] += currExtra;
            else
                arr[i] -= currExtra;
            ans += currExtra;
        }
    }
    return ans;
}
int main(){
    int arr[] = { 1, 2, 5, 9 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 2; 
  
    cout << countOp(arr, n, k)<<endl;     
    return 0;
}
