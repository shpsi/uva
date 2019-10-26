#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define PI acos(-1.0)
#define EPS 1e-4
int main(){
    int n,m;
    cin>>n>>m;
    int a[101], b[101];
    int as=0, bs=0;
    for(int i=0;i<n;++i){
        cin>>a[i]>>b[i];
        as += a[i];
        bs += b[i];
    }
    if(m<as || m>bs)
        cout<<"NO";
    else{
        cout<<"YES"<<endl;
        m -= as;
        for(int i=0;i<n;++i){
            cout << a[i] + min(m, b[i]-a[i])<<" ";
            m -= min(m , b[i]-a[i]);
        }
    }
    return 0;
}    
