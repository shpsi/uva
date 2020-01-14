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
vector<int> a;
int solve(vector<int>& vec, int idx){
    if(vec.size()==0 || idx == -1)
        return 0;
    vector<int> one, two;
    for(int i=0;i<vec.size();++i){
        if((vec[i]>>idx)&1)
            one.pb(vec[i]);
        else
            two.pb(vec[i]);
    }
    if(one.size()==0)
        return solve(two,idx-1);
    else if(two.size()==0)
        return solve(one,idx-1);
    else
        return min(solve(one,idx-1),solve(two,idx-1)) + (1<<idx);
}
int main(){
    fastio;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    cout<<solve(a,30)<<endl;
    return 0;
}    
