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
    vector<string> inp;
    string s;
    int mx = -1;
    int n=0;
    while(getline(cin, s)){
        mx = max(mx, (int)s.size());
        inp.pb(s);
        n++;
    }
    for(int i=0;i<mx+2;++i)
        cout<<"*";
    bool flg = true;
    cout<<"\n";
    for(int i=0;i<n;++i){
        int spc = mx - inp[i].length();
        if(spc%2){
            if(flg){
                cout<<"*";
                for(int i=0;i<spc/2;++i)
                    cout<<" ";
                cout<<inp[i];
                for(int i=0;i<(spc+1)/2;++i)
                    cout<<" ";
                cout<<"*\n";
            }
            else{
                cout<<"*";
                for(int i=0;i<(spc+1)/2;++i)
                    cout<<" ";
                cout<<inp[i];
                for(int i=0;i<(spc)/2;++i)
                    cout<<" ";
                cout<<"*\n";
            }
            flg = !flg;
        }
        else{
            cout<<"*";
            for(int i=0;i<spc/2;++i)
                cout<<" ";
            cout<<inp[i];
            for(int i=0;i<spc/2;++i)
                cout<<" ";
            cout<<"*\n";
        }
    }
    for(int i=0;i<mx+2;++i)
        cout<<"*";
    cout<<endl;
    return 0;
}    
