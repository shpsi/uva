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
int dsu[2505];
void init(int n){
    for(int i=0;i<=n;++i)
        dsu[i]=i;
}
int find(int u){
    if(u == dsu[u])
        return u;
    return dsu[u] = find(dsu[u]);
}
void connect(int u, int v){
    u = find(u);
    v = find(v);
    dsu[u] = v;
}
int main(){
    fastio;
    int perm[105], d[105];
    int n;
	cin >> n;
 
	init(n);
 
	for(int i = 1; i <= n; i++){
		cin >> perm[i];
	}
 
	for(int i = 1; i <= n; i++){
		cin >> d[i];
	}
    for(int i=1;i<=n;++i){
        if(i+d[i]<=n)
            connect(i,d[i]+i);
        if(i-d[i]>=0)
            connect(i,i-d[i]);
    }
    for(int i = 1; i < n; i++){
		if(find(i) != find(perm[i])){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
    return 0;
}    
