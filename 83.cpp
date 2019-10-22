#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define MAX 1000
#define INF 999999
int gcd(int a, int b){
    return b==0?a:gcd(a,b%a);
}
int recur(int i, int cnt, int last, int a[], int n, int k, int dp[][MAX]){
    cerr<<"debug:: "<<i<<" "<<cnt<<endl;
    if(i >= n)
        return INF;
    if(cnt==k)
        return 0;
    if(dp[i][cnt] != -1)
        return dp[i][cnt];
    int ans = recur(i+1, cnt, last, a, n, k, dp);
    if (cnt % 2 == 0) 
        ans=max(ans,recur(i + 1, cnt + 1, i, a, n, k, dp)); 
    else
        ans = max(ans, gcd(a[last], a[i]) + recur(i + 1, cnt + 1, i, a, n, k, dp));
    return dp[i][cnt] = ans;
}
int main(){
    int a[] = { 4, 5, 3, 7, 8, 10, 9, 8 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    int k = 4; 
    int dp[n][MAX]; 
    memset(dp, -1, sizeof dp); 
  
    cout << recur(0, 0, 0, a, n, k, dp) << endl;    
    return 0;
}
