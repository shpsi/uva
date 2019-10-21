#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void generateArr(int arr[], int n){
    if(n==0)
        return ;
    if(n==1){
        cout<<arr[0];
        return;
    }
    int suffixMax[n];
    memset(suffixMax, INT_MIN, n);
    suffixMax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;--i)
        suffixMax[i] = max(arr[i],suffixMax[i+1]);
    int minSoFar = arr[0];
    arr[0] = suffixMax[1];
    for(int i=1;i<n-1;++i){
        int temp = arr[i];
        arr[i] = abs(suffixMax[i+1] - minSoFar);
        minSoFar = min(temp, minSoFar);
    }
    arr[n-1] = minSoFar;
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int arr[] = { 1, 5, 2, 4, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    generateArr(arr, n);     
    return 0;
}
