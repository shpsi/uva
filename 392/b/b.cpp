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
int n;
int t[45][45];
ll dp[45][3][3][3];
ll solve(int n,int a,int b,int c){
    if(n==0)
        return 0;
	if(dp[n][a][b][c])
        return dp[n][a][b][c];
	ll b1=solve(n-1,a,c,b)+t[a][c]+solve(n-1,b,a,c);
	ll b2=solve(n-1,a,b,c)+t[a][b]+solve(n-1,c,b,a)+t[b][c]+solve(n-1,a,b,c);
	return dp[n][a][b][c]=min(b1,b2);
}
int main(){
    fastio;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            cin>>t[i][j];
    cin>>n;
    cout<<solve(n,0,1,2); // loved hanoi
    return 0;
}    
