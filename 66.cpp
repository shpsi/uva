 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define pb push_back
 int CountOfOddSum(int a[][2], int n){
     int dp[n][2];
     int cnt[n][2];
     memset(dp,0,sizeof(dp));
     memset(cnt, 0, sizeof(cnt));
     for(int i=0;i<n;++i){
         for(int j=0;j<2;++j){
             if(a[i][j]%2==0)
                 cnt[i][0]++;
             else
                 cnt[i][1]++;
         }
     }
     dp[0][0] = cnt[0][0];
     dp[0][1] = cnt[0][1];
     for(int i=1;i<n;++i){
             dp[i][0] = dp[i-1][0]*cnt[i][0] + dp[i-1][1]*cnt[i][1];
             dp[i][1] = dp[i-1][0]*cnt[i][1] + dp[i-1][1]*cnt[i][0];
     }
     return dp[n-1][1];
 }
 int main(){
     int a[][2] = { { 1, 2 }, { 3, 6 } }; 
     int n = sizeof(a) / sizeof(a[0]); 
 
     int ans = CountOfOddSum(a, n); 
 
     cout << ans << "\n"; 
     return 0;
 }
