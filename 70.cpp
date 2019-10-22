#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int countKdivPairs(int a[], int n, int k){
    map<int,int> mp;
    int ans=0;
    for(int i=0;i<n;++i){
        int currRem = a[i]%k;
        if(currRem == 0){
            ans += mp[0];
        }
        else{
            ans += mp[k-currRem];
        }
        mp[currRem]++;
    }
    return ans;
}
int main(){
    int A[] = { 2, 2, 1, 7, 5, 3 }; 
    int n = sizeof(A) / sizeof(A[0]); 
    int K = 4; 
    cout << countKdivPairs(A, n, K) << endl;     
    return 0;
}
