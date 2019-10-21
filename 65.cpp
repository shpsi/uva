#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int rightmostNonZero(int a[], int n){
    int c5=0;
    for(int i=0;i<n;++i){
        while(a[i]>0 && a[i]%5==0){
            a[i] /= 5;
            c5++;
        }
    }
    for(int i=0;i<n;++i){
        while(c5 && a[i]>0 && a[i]%2==0){
            a[i] /= 2;
            c5--;
        }
    }
    ll ans = 1;
    for(int i=0;i<n;++i){
        ans = (ans*a[i]%10)%10;
    }
    if(c5)
        ans = (ans*5)%10;
    return ans;
}
int main(){
    int a[] = { 7, 42, 11, 64 }; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    cout << rightmostNonZero(a, n) << endl;     
    return 0;
}
