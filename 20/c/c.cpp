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
int n,m;
vector<pair<int,int> > adj[100005];
ll dist[100005];
int par[100005];
ll INF = 1e18;
void print(int u){
    if(par[u]!=-1){
        print(par[u]);
    }
    cout << u+1<<" ";
}
int main(){
    fastio;
    int n,m;
    cin >>n>>m;
    for(int i=0;i<m;++i){
        int a,b,w;
        cin>>a>>b>>w;
        a--;
        b--;
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
    }
    for(int i=0;i<n;++i){
        dist[i] = INF;
        par[i] = -1;
    }
    priority_queue<int> pq;
    pq.push(0);
    dist[0]=0;
    while(!pq.empty()){
        int current = pq.top();
        pq.pop();
        for(pair<int,int> next : adj[current]){
            int v = next.first;
            int prevDist = next.second;
            if(dist[v] > prevDist + dist[current]){
                dist[v] = prevDist + dist[current];
                par[v] = current;
                pq.push(v);
            }
        }
    }
    if(par[n-1] != -1)
        print(n-1);
    else
        cout<<-1<<endl;
    return 0;
}    
