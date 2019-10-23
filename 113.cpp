#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void CheckSubarray(int a[], int n){
    int pre[n+1];
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;++i)
        pre[i] = pre[i-1]+a[i-1];
    vector<int> modu[n];
    for(int i=1;i<=n;++i)
        modu[pre[i]%n].pb(i-1);
    if (modu[0].size() > 0) { 
        cout << 0 << " " << modu[0][0]; 
        return; 
    } 
    for (int i = 1; i < n; i += 1) { 
        if(modu[i].size()>=2){
            cout << modu[i][0] + 1 << " " << modu[i][1]; 
            return; 
        } 
    } 
}
int main(){
    int arr[] = { 7, 3, 5, 2 }; 
  
    int N = sizeof(arr) / sizeof(arr[0]); 
  
    CheckSubarray(arr, N);    
    return 0;
}
