#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
#define pb push_back
#define PI acos(-1.0)
#define EPS 1e-4
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fout(S,x)            cout<<fixed<<setprecision(x)<<(S)<<endl
#define present(c,x) ((c).find(x) != (c).end())
#define T() ll t;cin>>t;while(t--)
#define mem(input,b) memset(input,b,sizeof(input))
#define ff first
#define ss second
#define fread(input) freopen("input","r",stdin)
#define fwrite(b) freopen("b","w",stdout)
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define FOREACH(i,c) for (__typeof ((c).begin()) i = (c).begin() ; i != (c).end() ; i++)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
bool isPrime(ll x){
    //trace(x);
    for(ll i=2;i*i<=x;++i)
        if(x%i==0)
            return true;
    return false;
}
ll gcd(ll a,ll b){
    return a==0?b:gcd(b%a,a);
}
int main(){
    fastio;
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll l,r;
        l=n;
        r=n+1;
        for(;isPrime(l);l--);
        //trace("ok");
        for(;isPrime(r);r++);
        ll p = l * r + (n - l - r + 1) * 2, q = 2 * l * r;
        ll g = gcd(p,q);
        cout<<p/g<<"/"<<q/g<<endl;
        
    }
    return 0;
}    
