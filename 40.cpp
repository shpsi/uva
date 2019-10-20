#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int power(int a, int b,int m){
    if(b == 0)
        return 1;
    if(b == 1)
        return a%m;
    int tmp = power(a,b/2,m);
    tmp = tmp % m;
    tmp = (tmp * tmp)%m;
    if(b&1)
        return (a*tmp)%m;
    return tmp;
}
int product(int arr[], int n){
    int N = 100010; 
    int mod = 1000000007; 
    vector<int> prime(N, 1); 
    prime[0] = prime[1] = 0; 
    int i = 2; 
    while (i * i < N) 
    { 
        if (prime[i]) 
            for (int j = 2 * i; 
                     j <= N;j += i) 
                prime[j] = 0; 
  
        i += 1; 
    } 
    int t = power(2, n-1, mod-1);
    int ans = 1;
    for (int j = 0; j < n; j++) 
    { 
        int i = arr[j]; 
        if( prime[i]) 
        { 
            ans *= power(i, t, mod); 
            ans %= mod; 
        } 
    } 
    return ans; 
}
int main(){
    int A[] = {3, 7}; 
      
    int n = sizeof(A) / sizeof(A[0]); 
      
    printf("%d\n", product(A, n));     
    return 0;
}
