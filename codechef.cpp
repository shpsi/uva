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
    int t;
    cin>>t;
    while(t--){
        int n,m,w,h;
        cin>>n>>m>>w>>h;
        string str;
        cin>>str;
        vector<pair<int,int> > arr(m);
        int u,d,l,r;
        u=r=d=l=1e9;
        for(int i=0;i<m;i++){
            cin>>arr[i].ff>>arr[i].ss;
            u = min(u,h-arr[i].ss);
            r = min(r,w-arr[i].ff);
            d = min(d,arr[i].ss);
            l = min(l,arr[i].ff);

        }
        int ans = 1e9;
        for(int i=0;i<m;i++){
            for(int j = i+1;j<m;j++){
                ans = min(ans,(arr[i].ff-arr[j].ff)*(arr[i].ff-arr[j].ff)+(arr[i].ss-arr[j].ss)*(arr[i].ss-arr[j].ss));

            }

        }
        for(int i=0;i<str.size();i++){
            if(str[i]=='U'){
                ans = min(ans,(2*u*2*u));
                u = d;

            } 
            if(str[i]=='D'){
                ans = min(ans,(2*d*2*d));
                d = u;

            } 
            if(str[i]=='L'){
                ans = min(ans,(2*l*2*l));
                l = r;   

            } 
            if(str[i]=='R'){
                ans = min(ans,(2*r*2*r));
                r = l;

            } 

        }
        long double p=sqrt(ans);
        cout<<p<<endl;
    }
    return 0;
}    
