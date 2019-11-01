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
#define maxn 1e5+5
#define lg 20
ll sptable[maxn][lg];
set<pii> st;
vector<pii> adj[maxn];
ll dist[maxn];
ll st[maxn];
ll ft[maxn];
ll time = 0;
bool vis[maxn];
bool is_ancestor(int v, int u){
    return (st[v]<=st[u] && ft[u]<=ft[v]);
}
void DFS(ll v){
    vis[v] = true;
    st[v] = time++;
    for(ll i=0;i<adj[v].size();++i){
        if(!vis[adj[v][i].ff]){
            dist[adj[v][i].ff] = dist[v] + adj[v][i].ss;
            sptable[adj[v][i].ff][0] = v;
            DFS(ad[v][i].ff);
        }
    }
    ft[v] = time++;
}
ll lca(ll v, ll u){
    for(ll i=lg;i>=0;--i){
        if(!is_ancestor(sptable[v][i],u)){
            v=sptable[v][i];
        }
    }
    return is_ancestor(v,u) ? v : sptable[v][0];
}
ll get_dist(ll v, ll u){
    return dist[v] + dist[u] - 2*dist[lca(v,u)];
}
ll totWeight = 0;
void add(ll v){
    if(st.size() == 0){
        st.insert(mp(st[v],v));
    }
    else{
        set<pii>::iterator pre, it = upper_bound(st.begin(), st.end(), mp(st[v], v));
    }
}
void remove(ll v){
    if(st.size() == 1){
        st.erase(mp(st[v],v));
    }
    else{

    }
}
int main(){
    fastio;
    ll n;
    cin>>n;
    for(ll i=0;i<n-1;++i){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }
    sptable[1][0]=1;
    DFS(1);
    for(ll i=0;i<lg;++i){
          for(int j=1;j<=n;++j)
              sptable[j][i] = sptable[sptable[j][i-1]][i-1];
    }
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++)
    {
        char type;
        cin>>type;

        if (type=='+')
        {
            ll v;
            cin>>v;
 
            add(v);
        }
 
        if (type=='-')
        {
            ll v;
            cin>>v;
 
            rem(v);
        }
 
        if (type=='?')
        {
            cout<<totWeight/2<<endl;
        }
    }
    return 0;
}    
