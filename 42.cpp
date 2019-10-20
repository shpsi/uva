#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int cntSubsets(int arr[], int n){
    unsigned int totSub = pow(2,n);
    int ans = 0;
    for(int i=0;i<totSub;++i){
        if((i&(i>>1)) == 0)
            ans++;
    }
    return ans;
}
int main(){
    int arr[] = { 3, 5, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << cntSubsets(arr, n) << endl;     
    return 0;
}
