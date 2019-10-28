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
int n, m;
vector<vector<char> > inp;
char c;
vector<char> give_neigh(int i, int j){
    vector<char> res;
    if(i>0 && i<n-1){
        res.pb(inp[i-1][j]);
        res.pb(inp[i+1][j]);
    }
    else if(i>0){
        res.pb(inp[i-1][j]);
    }
    else if(i<n-1){
        res.pb(inp[i+1][j]);
    }
    if (j > 0 && j < m-1) {
        res.pb(inp[i][j-1]);
        res.pb(inp[i][j+1]);
    }
    else if (j > 0) res.pb(inp[i][j-1]);
    else if (j < m-1) res.pb(inp[i][j+1]);
    return res;
}
int main(){
    fastio;
    cin >>n>>m>>c;
    inp.resize(n);
    for(int i=0;i<n;++i)
        inp[i].resize(m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin >>inp[i][j];
    set<char> st;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(inp[i][j] == c){
                vector<char> neigh = give_neigh(i,j);
                for(int i=0;i<neigh.size();++i){
                    if(neigh[i] != '.' && neigh[i] != c)
                        st.insert(neigh[i]);
                }
            }
        }
    }
    cout<<st.size()<<endl;
    return 0;
}    
