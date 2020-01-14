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
const ll mod = 1e9+7;
const int maxn = 3e5+5;
struct BIT{
    int sz;
    ll data[maxn];
    void upd(int idx, ll delta){
        int i=idx;
        for(;i<=sz;i+=(i&(-i)))
            data[i] += delta;
    }
    ll getSum(int idx){
        ll sum=0;
        int i = idx;
        while(i>0){
            sum += data[i];
            i-=(i&(-i));
        }
        return sum;
    }
};
BIT bit1, bit2;
int n, p[maxn], id[maxn], ts;
int l[maxn], r[maxn];
ll dep[maxn];
vector<int> g[maxn];
void dfs(int u) {
  id[u] = ++ts;
  l[u] = r[u] = id[u];
  for(int v:g[u])
  {
    dep[v] = dep[u]+1;
    dfs(v);
    r[u] = r[v];
  }
}
int main(){
    fastio;
    cin >> n;
    for(int i=2;i<=n;++i){
        cin>>p[i];
        g[p[i]].pb(i);
    }
    //trace("ok");
    dfs(1);
    //trace("ok1");
    bit1.sz = bit2.sz = n;
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int v;
            ll x,k;
            cin>>v>>x>>k;
            bit1.upd(l[v],x%mod);
            bit1.upd(l[v],(dep[v]*k)%mod);
            bit1.upd(r[v]+1,-x+mod);
            bit1.upd(r[v]+1,mod-((dep[v]*k)%mod));
            bit2.upd(l[v],mod-k);
            bit2.upd(r[v]+1,(mod+k)%mod);
        }
        else{
            int v;
            cin>>v;
            ll answer = (bit1.getSum(id[v])%mod + (bit2.getSum(id[v])%mod*dep[v]%mod)%mod)%mod;
            cout<<answer<<endl;
        }
    }
    return 0;
}    
