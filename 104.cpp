#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void ComputePrefixXor(int arr[], int PrefixXor[], int n) {
    PrefixXor[0] = arr[0];
    for(int i=1;i<n;++i)
        PrefixXor[i] = arr[i] ^ PrefixXor[i-1];
}
int Xor_Sum(int a[], int n){
    int PrefixXor[n];
    ComputePrefixXor(a, PrefixXor, n);
    int sum=INT_MIN, idx;
    for(int i=0;i<n;++i){
        int tmp = PrefixXor[i] + (PrefixXor[n-1] ^ PrefixXor[i]);
        if(tmp>sum){
            sum=tmp;
            idx=i;
        }
    }
    return idx+1;
}
int main(){
    int arr[] = { 1, 4, 6, 3, 8, 13, 34, 2, 21, 10 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
      
    // Function call 
    cout << Xor_Sum(arr, n) << endl;    
    return 0;
}
