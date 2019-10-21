#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int getNumber(int n, int k){
    int evenStart;
    if(n%2)
        evenStart = n/2+1;
    else
        evenStart = n/2;
    if(k<=evenStart)
        return k*2-1;
    return (k-evenStart)*2;
}
int main(){
    int n = 8, k = 5; 
  
    cout << getNumber(n, k) << endl;     
    return 0;
}
