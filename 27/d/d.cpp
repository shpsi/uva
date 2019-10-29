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
int l[101], r[101];
bool vis[101];
int par[101];
void dfs(int node, int color){
    vis[node] = true;
    par[node] = color;
    for(int i=0;i<m;++i){
        if(i == node)
            continue;
        int a,b,c,d;
        a=l[node];
        b=r[node];
        c=l[i];
        d=r[i];
        if((r[i] > r[node] && l[i] < r[node] && l[i] > l[node]) || (l[i] < l[node] && r[i] < r[node] && r[i] > l[node])){
            if(vis[i] == false){
                dfs(i,1-color);
            }
            else if(par[i] == color){
                cout << "Impossible\n";
                exit(0);
            }
        }
    }
}
int main(){
    fastio;
    cin >> n >> m;
    for(int i=0;i<m;++i){
        cin>>l[i]>>r[i];
        if(l[i]>r[i])
            swap(l[i], r[i]);
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<m;++i){
        if(vis[i] == false)
            dfs(i,0);
    }
    for(int i = 0; i < m; i++)
    if(par[i]!= 0)
      cout << 'i';
    else
      cout << 'o';
    cout << '\n';
    return 0;
}    
