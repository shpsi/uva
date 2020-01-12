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
int n,m;
int a[maxn];
int cnt[maxn];
ll gcd(ll a, ll b){
    return a==0?b:gcd(b%a,a);
}
int main(){
    fastio;
    cin >>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(a[i]<=m){
            cnt[a[i]]++;
        }
    }
    for (int i = m; i >= 1; --i) {
		for (int j = i + i; j <= m; j += i){
			cnt[j] += cnt[i];
            //trace(cnt[i],cnt[j],i,j);
        }
    }
    //for(int i=1;i<=m;++i)
        //trace(cnt[a[i]],i);
    pair<int,int> mx = mp(0,1);
    for(int i=1;i<=m;++i)
        mx = max(mx, mp(cnt[i],i));
    ll superLcm = mx.ss, targetLcm=1;
    vector<ll> ans;
    for (int i = 0; i < n; ++i)
		if (superLcm % a[i] == 0)
			ans.push_back(i + 1),targetLcm = targetLcm * a[i] / gcd(targetLcm, (ll)a[i]);
    //trace("ok2");
    printf("%lld %d\n", targetLcm, (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i)
		printf("%lld ", ans[i]);
	printf("\n");
    return 0;
}    
