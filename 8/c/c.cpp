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
int n,dp[1<<24],X,Y,MX,c[33][33],s[33];
vector<pair<int,int> >v;
inline int len(int x,int y,int a,int b){
    return (x-a)*(x-a)+(y-b)*(y-b);
}
int x,y,a,b,i,j;
inline int calc(int msk){
    if(msk==MX)
        return 0;
    if(dp[msk]!=-1)
        return dp[msk];
    dp[msk]=2e9;
    for(int i=0;i<n;++i){
        if((msk>>i)&1)
            continue;
        for(int j=i;j<n;++j){
            if((msk>>j)&1)
                continue;
            dp[msk]=min(dp[msk],s[i]+c[i][j]+s[j]+calc(msk|(1<<i)|(1<<j)));
        }
        break;
    }
    return dp[msk];
}
vector<int>ans;
void path(int msk){
    if(msk==MX)
        return;
    int op=calc(msk);
    for(int i=0;i<n;++i){
        if((msk>>i)&1)
            continue;
        int x=v[i].first;
        int y=v[i].second;
        for(j=i;j<n;++j){
            if((msk>>j)&1)
                continue;
            int a=v[j].first;
            int b=v[j].second;
            if(op==2*s[j]+calc(msk|(1<<j))){
                ans.push_back(j+1);
                ans.push_back(0);
                path(msk|(1<<j));
                return;
            }
            if(op==s[i]+c[i][j]+s[j]+calc(msk|(1<<i)|(1<<j))){
                ans.push_back(i+1);
                ans.push_back(j+1);
                ans.push_back(0);
                path(msk|(1<<i)|(1<<j));
                return;
            }
        }
        break;
    }
}
 
int main() {
    scanf("%d%d%d",&X,&Y,&n);
    v.resize(n);
    for(int i=0;i<n;++i)
        scanf("%d%d",&v[i].first,&v[i].second);
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j)
            c[i][j]=len(v[i].first,v[i].second,v[j].first,v[j].second);
        s[i]=len(X,Y,v[i].first,v[i].second);
    }
    memset(dp,-1,sizeof dp);
    MX=(1<<n)-1;
    printf("%d\n",calc(0));
    ans.push_back(0);
    path(0);
    for(int i=0;i<ans.size();++i)
        printf("%d ",ans[i]);
    return 0;
}
