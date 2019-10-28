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
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}
void exgcd(long long a,long long b,long long &d,long long &x,long long &y){
	if(b==0) {
		d=a;x=1,y=0;
	}
	else{
		exgcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}
int main(){
    fastio;
    ll a, b, c;
    cin>>a>>b>>c;
    ll ans = gcd(a,b);
    if(c%ans != 0)
        cout<<-1<<endl;
    else{
        long long x,y,d;
		exgcd(a,b,d,x,y);
		cout<<-x*c/ans<<" "<<-y*c/ans<<endl;
    }
    return 0;
}    
