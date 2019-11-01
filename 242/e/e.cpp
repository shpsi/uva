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
#define maxn 100005
#define lg 32
int n;
int segtree[4*maxn][32];
int lazy[4*maxn];
int a[maxn];
void build(int curr,int l, int r){
    if(l==r){
        for(int i=0;i<lg;++i)
            if(a[l] & (1<<i)){
                segtree[curr][i]=1;
            }
    }
    int mid=(l+r)>>1;
    build(2*curr,l,mid);
    build(2*curr+1,mid+1,r);
    for(int i=0;i<lg;++i)
        segtree[curr][i] = segtree[2*curr][i] + segtree[2*curr+1][i]; 
}
void upd(int curr, int l, int r, int ql, int qr, int x){

}
void pushLazy(int curr, int l, int r){
    if(lazy[curr]){
        int mid = (l+r)>>1;
        lazy[2*curr] = lazy[2*curr] ^ lazy[curr];
        lazy[2*curr+1] = lazy[2*curr+1] ^ lazy[curr];
        for(int i=0;i<lg;++i){
            if(lazy[n] & (1<<i)){
                segtree[curr][i] = 
            }
        }
    }
}
int query(int curr, int l, int r, int ql, int qr){
    if(l>qr || r<ql)
        return 0;
    if(l>=ql && qr>=r){
        ll ans = 0;
        for(int i=0;i<lg;++i)
            ans += segtree[curr][i]*(1<<i);
        return ans;
    }

    int mid = (l+r)>>1;
    return query(2*curr,l,mid,ql,qr) + query(2*curr+1,mid+1,r,ql,qr);
}
int main(){
    fastio;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    build(1,1,n);
    int q;
    cin>>q;
    while(q--){
        if(type==1){
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<nl;
        }
        else{
            cin>>l>>r>>x;
            upd(1,1,n,l,r,x);
        }
    }
    return 0;
}    
