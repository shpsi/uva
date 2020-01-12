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
const int maxn = 1000005;
struct node{
    int a;
    int b;
    int c;
}segTree[4*maxn];
node merge(node x, node y){
    node z;
    int t = min(x.b, y.c);
    z.a = x.a+y.a+2*t;
    z.b = x.b+y.b-t;
    z.c = x.c+y.c-t;
    return z;
}
string str;
void build(int curr, int l,int r){
    if(r==l){
        if(str[l] == ')'){
            segTree[curr].c = 1;
            segTree[curr].b = 0;
            segTree[curr].a = 0;
        }
        else{
            segTree[curr].b = 1;
            segTree[curr].c = 0;
            segTree[curr].a = 0;
        }
        return ;
    }
    int mid = (l+r)/2;
    build(2*curr+1, l, mid);
    build(2*curr+2, mid+1, r);
    node x = segTree[2*curr+1];
    node y = segTree[2*curr+2];
    segTree[curr] = merge(x,y);
    //trace(curr, segTree[curr].a, segTree[curr].b, segTree[curr].c);
}
node get(int curr,int l, int r, int askedX,int askedY){
    node empty = {0,0,0};
    //trace(curr,l,r,askedX,askedY);
    if(askedX>=r || askedY<=l){
        //trace("1st case");
        return empty;
    }
    if(askedX<=l && askedY>=r){
        //trace("2nd case");
        return segTree[curr];
    }
    //trace("came in generic code part");
    int mid = (l+r)/2;
    node x = get(2*curr+1, l, mid, askedX, askedY);
    node y = get(2*curr+2, mid+1, r, askedX, askedY);
    node z = merge(x,y);
    return z;
}
int main(){
    fastio;
    cin >> str;
    int n = str.length();
    build(0,0,n);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        cout<<get(0,0,n,l,r).a<<endl;
    }
    return 0;
}    
