#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,a;
    cin>>n>>m>>a;
    long long  x = n/a;
    if(n%a !=0) 
        x++;
    long long  y = m/a;
    if(m%a!=0)
        y++;
    long long  p = x*y;
    cout<<p<<endl;
    return 0;
}    
