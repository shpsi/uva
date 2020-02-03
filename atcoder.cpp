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
const int maxn=1e5+5;
const int mod=1e9+7;
int main(){
    fastio;
    int n,m;
    cin>>n>>m;
    string s;
    cin >>s;
    stack<int> st;
    int i=n;
    while(i>0){
        bool ok = false;
        for(int j=m;j>=1;--j){
            if(i-j>=0 && s[i-j]=='0'){
                ok = true;
                st.push(j);
                i-=j;
                break;
            }
        }
        if(ok==false){
            cout<<-1<<endl;
            return 0;
        }
    }
    while(!st.empty()){
        int tp = st.top();
        st.pop();
        cout<<tp<<" ";
    }
    cout<<endl;
    return 0;
}
