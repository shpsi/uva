#include<bits/stdc++.h>
using namespace std;
int binom(int n, int k){
    int dp[n+1][k+1];
    for(int i = 0; i <=n ;++i){
        for(int j=0;j<= min(i,k); ++j){
            if(j==0 || j==k)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][k];
}
int cntSubSeq(vector<int> arr, int k){
    sort(arr.begin(), arr.end());
    int num = arr[k-1];
    int cntX = 0, Y = 0;
    for(int i=k-1;i>=0;--i){
        if(arr[i] == num)
            Y++;
    }
    for(int i=0;i<arr.size();++i){
        if(arr[i] == num)
            cntX++;
    }
    cout << binom(cntX,Y) << endl; 
}
int main(){
    vector<int> arr(4);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    cout << cntSubSeq(arr,2);
    return 0;
}
