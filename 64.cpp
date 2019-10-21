#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int digCount(int n){
    int cnt=0;
    while(n){
        n/=10;
        cnt++;
    }
    return cnt;
}
int RSF(int n){
    while(n>=10){
        int dc = digCount(n);
        int store[dc];
        int i=0;
        while(n){
            store[i] = n%10;
            n/=10;
            i++;
        }
        for(int j=0;j<dc-1;++j)
            n = n*10 + abs(store[j]-store[j+1]);
    }
    return n;
}
int main(){
    int n = 614; 
  
    // Passing n to RSF function and getting answer 
    int ans = RSF(n); 
  
    // Printing the value stored in ans 
    cout << ans<<endl;     
    return 0;
}
