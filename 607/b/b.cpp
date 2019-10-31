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
int main(){
    fastio;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    int dp[n][n];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            dp[i][j]=INT_MAX;
    for(int len=1;len<=n;++len){
        for(int i=0;i+len-1<n;++i){
            int j=i+len-1;
            if(len==1){
                dp[i][j]=1;
            }
            else if(len==2){
                dp[i][j] = (a[i]==a[j]?1:2);
            }
            else{
                if(a[i]==a[j])
                    dp[i][j] = dp[i+1][j-1];
                for(int k=i;k<j;++k){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}    
