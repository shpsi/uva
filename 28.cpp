#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void find_idx(int arr[], int n){
    vector<int> ans;
    int sum=arr[n-1];
    for(int i=n-2;i>=0;--i){
        if(sum == arr[i]){
            ans.pb(i);
        }
        sum += arr[i];
    }
    for(auto it:ans)
        cout<<it<<" ";
    cout<<endl;
}
int main(){
    int arr[] = { 36, 2, 17, 6, 6, 5 }; 
    int n = sizeof(arr) / sizeof(int); 
  
    find_idx(arr, n);     
    return 0;
}
