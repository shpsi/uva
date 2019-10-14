#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int x, int y){
    return y? gcd(y,x%y):x;
}
int main(){
    int hsh[1000010] = {0};
    ll n,count;
    while(scanf("%lld",&n) == 1){
        count = 0;
        for(ll i=1;i*i<=n;++i){
            for(ll j=i+1;j*j<=n;j+=2){
                if(gcd(i,j) == 1){
                    ll a = j*j - i*i;
                    ll b = 2*i*j;
                    ll c = i*i+j*j;
                    if(c>n)
                        break;
                    ll ma = a;
                    ll mb = b;
                    ll mc = c;
                    while(mc <= n){
                        hsh[ma] = hsh[mb] = hsh[mc] = 1;
                        ma += a;
                        mb += b;
                        mc += c;
                    }
                    count++;
                }
            }
        }
        ll ans = n;
        for(ll i=1;i<=n;++i){
            ans = ans - hsh[i];
            hsh[i] = 0;
        }
        cout<<count << " " <<ans<<endl;
    }
    return 0;
}
