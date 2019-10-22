#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define MAX_ELEMENT 50
#define MAX 10000
int dp[MAX_ELEMENT][50][MAX];
int Max_Xor(int a[], int i, int rem, int mask, int n){
    if(i>=n){
        if(rem == 0)
            return mask;
        else
            return 0;
    }
    if(dp[i][rem][mask] != -1)
        return dp[i][rem][mask];
    int ans = 0;
    if(rem>0)
        ans = Max_Xor(a,i+1,rem-1,mask^a[i], n);
    ans = max(ans, Max_Xor(a,i+1,rem,mask,n));
    return dp[i][rem][mask] = ans;
}
int main(){
    int arr[] = { 2, 5, 4, 1, 3, 7, 6, 8 }; 
    int n = sizeof(arr) / sizeof(int); 
    int k = 3; 
  
    memset(dp, -1, sizeof(dp)); 
  
    cout << Max_Xor(arr, 0, k, 0, n) << endl;    
    return 0;
}
