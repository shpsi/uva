#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void SieveOfEratosthenes(int MAX, vector<int>& primes)
{
    bool prime[MAX + 1];
    memset(prime, true, sizeof(prime));

    // Seive method to check if prime or not
    for (long long p = 2; p * p <= MAX; p++) {
        if (prime[p] == true) {
            // Multiples
            for (long long i = p * p; i <= MAX; i += p)
                prime[i] = false;
        }
    }

    // Pre-store all the primes
    for (long long i = 2; i <= MAX; i++) {
        if (prime[i])
            primes.push_back(i);
    }
}
int findLongest(int a[], int n){
    vector<int> primes;
    SieveOfEratosthenes(a[n - 1], primes); 
    map<int,int> mp;
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[n-1]=1;
    mp[a[n-1]]=n-1;
    for(int i=n-2;i>=0;--i){
        int num = a[i];
        dp[i] = 1;
        for(auto it:primes){
            int xx = it * num;
            if(xx > a[n-1])
                break;
            else if(mp.find(xx) != mp.end()){
                dp[i] = max(dp[i], dp[mp[xx]]+1);
            }
        }
        mp[a[i]]=i;
    }
    int ans = 1; 
  
    // Find the longest 
    for (int i = 0; i < n; i++) { 
        ans = max(ans, dp[i]); 
    } 
  
    return ans; 
}
int main(){
    int a[] = { 1, 2, 5, 6, 12, 35, 60, 385 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << findLongest(a, n) << endl;     
    return 0;
}
