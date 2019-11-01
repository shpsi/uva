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
    int n,k;
    vector<int>a;
    cin>>n>>k;
    a.resize(n+1);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    bool dp[505][505][2]; // memory-efficient dp array
    memset(dp, true, sizeof(dp));
    dp[0][0][0]=true;
    for(int i=1;i<=n;++i){
        int now = i%2;
        int last = 1-now;
        int x = a[i];
        for(int sum=0;sum<=k;sum++){
            for(int subsetsum=0;subsetsum<=sum;subsetsum++){
                dp[sum][subsetsum][now] = dp[sum][subsetsum][last];
                if(x<=sum){
                    dp[sum][subsetsum][now] |= dp[sum-x][subsetsum][last];
                    if(x<=subsetsum)
                        dp[sum][subsetsum][now] |= dp[sum-x][subsetsum-x][last];
                }
            }
        }
    }
    vector <int> res;
	for(int i = 0; i <= k; i++)
		if(dp[n%2][k][i])
			res.push_back(i);
	cout << res.size() << endl;
	for(int x : res)
	    cout << x << " ";
	cout << endl;
    return 0;
}    
