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
struct node{
    int d;
    int s;
    string ans;
};
bool vis[505][5005];
int main(){
    fastio;
    int d,s;
    cin>>d>>s;
    queue<node> q;
    node st;
    st.d = 0;
    st.s = 0;
    st.ans = "";
    vis[0][0] = true;
    q.push(st);
    while(!q.empty()){
        node curr = q.front();
        q.pop();
        //trace(curr.d, curr.s, curr.ans);
        if(curr.d==0 && curr.s == s){
            puts(curr.ans.c_str());
            return 0;
        }
        for(int i=0;i<=9;++i){
            int rem = curr.d*10+i;
            rem %= d;
            int newSum = curr.s + i;
            //trace(rem, newSum);
            if(newSum <= s && !vis[rem][newSum]){
                node nxt;
                nxt.d = rem;
                nxt.s = newSum;
                nxt.ans = curr.ans + char(i+'0');
                q.push(nxt);
                vis[rem][newSum] = true;
            }
        }
    }
    puts("-1");
    return 0;
}    
