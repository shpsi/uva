#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int getMinOps(vector<int> a){
    int n = a.size();
    int small = *min_element(a.begin(), a.end());
    int large = *max_element(a.begin(), a.end());
    int dp[n+1][large+1];
    for(int j = small; j <= large; ++j)
        dp[0][j] = abs(a[0] - j);
    for(int i = 1; i <= n; ++i){
        int curr = INT_MAX;
        for(int j = small; j <= large; ++j){
            curr = min(curr, dp[i-1][j]);
            dp[i][j] = curr + abs(a[i] - j);
        }
    }
    int result = INT_MAX;
    for(int j = small; j <= large; ++j)
        result = min(result, dp[n-1][j]);
    return result;
}
int main(){
    vector<int> arr;
    arr.pb(1);
    arr.pb(2);
    arr.pb(1);
    arr.pb(4);
    arr.pb(3);
    cout << getMinOps(arr);
    return 0;
}
