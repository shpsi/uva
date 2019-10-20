#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int cntElements(int arr[] , int n){
    int b[n];
    for(int i=0;i<n;++i)
        b[i] = arr[i];
    sort(b,b+n);
    int cnt=0;
    for(int i=0;i<n;++i)
        if(arr[i] != b[i])
            cnt++;
    return cnt;
}
int main(){
    int arr[] = { 1, 2, 6, 2, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << cntElements(arr, n) << endl;     
    return 0;
}
