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
const int mod = 1e9+7;
ll power(ll a, int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    ll temp = power(a,b/2);
    if(b&1)
        return ((temp*temp)%mod*a)%mod;
    else
        return (temp*temp)%mod;
}
ll getInv(ll a){
    return power(a,mod-2);
}
ll binomial(int c, int k){
    ll res = 1;
    for(int i=0;i<k;++i){
        res = res * ((c-i)%mod*getInv(i+1)%mod)%mod;
    }
    return res;
}
map<int,int>cnt;
int main(){
    fastio;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        for(int p=2;p*p<=x;++p){
            while(x%p==0){
                cnt[p]++;
                x /= p;
            }
        }
        if(x>1)
            cnt[x]++;
    }
    ll answer = 1;
    for (auto x : cnt) {
		answer = answer * binomial(x.second + n - 1, n - 1) % mod;
	}
	printf("%lld\n", answer);
    return 0;
}    
