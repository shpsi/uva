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
double a,v,l,d,w;
double dist(double v0, double t){
    return v0*t + 0.5 * a * t * t;
}
double travel_time(double distance, double v0) {
  double t1 = (sqrt(v0*v0 + 2*a*distance) - v0) / a;
  double t2 = (v - v0) / a;
  return t1 <= t2 ? t1 : t2 + (distance - dist(v0, t2)) / v;
}

double solve() {
  if (v <= w) return travel_time(l, 0);
  double tw = w / a, dw = dist(0, tw);
  if (dw >= d) return travel_time(l, 0);
  return tw + 2*travel_time(0.5*(d-dw), w) + travel_time(l-d, w);
}
int main() {
  cin >> a >> v >> l >> d >> w;
  fout(solve(),12);
  //printf("%.6lf\n", solve());
  return 0;
}
