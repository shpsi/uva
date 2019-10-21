#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int fact[8];
void pre(){
    fact[0]=1;
    for(int i=1;i<8;++i)
        fact[i] = i*fact[i-1];
}
int CountPermutation(int a[], int n){
    int ways=1;
    int curr=1;
    sort(a,a+n);
    for(int i=1;i<n;++i){
        if(a[i] == a[i-1])
            curr++;
        else{
            ways *= fact[curr];
            curr=1;
        }
    }
    ways *= fact[curr];
    return ways;
}
int main(){
    int a[] = { 1, 2, 4, 4, 2, 4 }; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    // Pre-calculating factorials 
    pre(); 
  
    cout << CountPermutation(a, n) << endl;     
    return 0;
}
