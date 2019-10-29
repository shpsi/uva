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
    int play[n+1];
    int won[n+1];
    memset(play,0,sizeof(play));
    memset(won,0,sizeof(won));
    int tot = n*(n-1)/2;
    for(int i=0;i<tot-1;++i){
        int x,y;
        cin>>x>>y;
        play[x]++;
        play[y]++;
        won[x]++;
    }
    vector<int> player;
    for(int i=1;i<=n;++i){
        if(play[i] == n-2)
            player.pb(i);
    }
    if(won[player[0]] > won[player[1]])
        cout<<player[0] << " " << player[1]<<endl;
    else
        cout<<player[1]<<" "<<player[0]<<endl;
    return 0;
}    
