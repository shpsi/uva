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
    string s;
    cin>>s;
    int n = s.length();
    int dp[n];
    memset(dp, 0, sizeof(dp));
    stack<int> st;
    for(int i=0;i<n;++i){
        //trace(i, s[i]);
        if(s[i]==')' && !st.empty()){
            //trace("debug1");
            int idx = st.top();
            st.pop();
            if(idx == 0){
                dp[i] = i+1;
            }
            else{
                dp[i] = dp[idx-1] + (i-idx) + 1;
            }
        }
        else if(s[i]=='('){
            //trace("debug2");
            st.push(i);
        }
    }
    int len = 0, cnt = 0;
    for(int i=0;i<n;++i){
        if(dp[i] > len){
            len = dp[i];
            cnt = 1;
        }
        else if(dp[i] == len){
            cnt++;
        }
    }
    if(len)
        cout << len << " " << cnt << endl;
    else
        cout<<"0 1"<<endl;
    return 0;
}    
