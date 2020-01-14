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
    string a,b,c;
    a=b=c="";
    int i=0;
    while(s[i]!='+')
        a += s[i],i++;
    i++;
    while(s[i]!='=')
        b += s[i],i++;
    i++;
    //trace("ok");
    while(i<s.length())
        c+=s[i],i++;
    int x,y,z;
    x=a.length();
    y=b.length();
    z=c.length();
    if(x+y==z){
        cout<<s<<endl;
    }
    else if(x+y+2==z){
        if(x>y){
            cout<<a<<"+"<<b<<"|"<<"="<<c.substr(0,c.length()-1)<<endl;
        }
        else{
            cout<<a<<"|+"<<b<<"="<<c.substr(0,c.length()-1)<<endl;
        }
    }
    else if(x+y==z+2){
        if(x>y){
            cout<<a.substr(0,a.length()-1)<<"+"<<b<<"="<<c<<"|"<<endl;
        }
        else{
            cout<<a<<"+"<<b.substr(0,b.length()-1)<<"="<<c<<"|"<<endl;
        }
    }
    else{
        cout<<"Impossible";
    }
    return 0;
}    
