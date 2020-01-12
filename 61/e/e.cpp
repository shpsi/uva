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
const int maxn = 1e6+5;
ll bit[maxn];
int n;
ll getSum(int i){
    ll sum = 0;
    while(i>0){
        //trace(i);
        sum += bit[i];
        i-= (i&(-i));
    }
    return sum;
}
void upd(int i){
    for(;i<n;i+=i&-i){
        //trace(i);
        bit[i]++;
    }
}
int main(){
    fastio;
    cin >> n;
    vector<pair<ll,int> > inp;
    for(int i=0;i<n;++i){
        ll x;
        cin>>x;
        //trace(i,x,n);
        inp.pb(mp(x,i));
    }
    sort(all(inp));
    ll answer = 0;
    for(int i=0;i<n;++i){
        ll curr = getSum(inp[i].ss);
        answer += 1ll * (i-curr) * (inp[i].ss-curr);
        upd(inp[i].ss+1);
    }
    cout<<answer<<endl;
    return 0;
}    
