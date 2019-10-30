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
    int row, col;
    cin>>row>>col;
    vector<string> s;
    s.resize(row);
    for(int i=0;i<row;++i)
        cin>>s[i];
    int dp[505][27][27];
    int aa[505][27][27];
    int bb[505][27][27];
    // memset sucks
    for(int i=0;i<505;++i){
        for(int j=0;j<27;++j){
            for(int k=0;k<27;++k){
                dp[i][j][k] = INT_MAX;
                aa[i][j][k] = -1;
                bb[i][j][k] = -1;
            }
        }
    }
    for(int i=0;i<27;++i)
        for(int j=0;j<27;++j)
            dp[row][i][j] = 0;
    for(int r=row-1;r>=0;--r){
        for(int a=0;a<27;++a){
            for(int b=0;b<27;++b){
                if(a == b)
                    continue;
                else{
                    int cost = 0;
                    for(int c=0;c<col;++c){
                        if(c%2)
                            cost += (s[r][c] != (b+'a'));
                        else
                            cost += (s[r][c] != (a+'a'));
                    }
                    for(int ja=0;ja<27;++ja){
                        if(ja == a){
                            continue;
                        }
                        for(int jb=0;jb<27;jb++){
                            if(jb == b)
                                continue;
                            else{
                                if(ja == jb)
                                    continue;
                                if(dp[r+1][ja][jb] < dp[r][a][b]){
                                    dp[r][a][b] = dp[r+1][ja][jb];
                                    aa[r][a][b] = ja;
                                    bb[r][a][b] = jb;
                                }
                            }
                        }
                    }
                    if(dp[r][a][b] < INT_MAX)
                        dp[r][a][b] += cost;
                }
            }
        }
    }
    int best = INT_MAX;
    int ansa,ansb;
    for(int i=0;i<27;++i){
        for(int j=0;j<27;++j){
            if(best>dp[0][i][j]){
                best = dp[0][i][j];
                ansa = aa[0][i][j];
                ansb = bb[0][i][j];
            }
        }
    }
    cout<<best<<endl;
    int r=0;
    while(r<row){
        for(int i=0;i<col;++i){
            if(i&1)
                cout<<(char)('a'+ansa);
            else
                cout<<(char)('a'+ansb);
        }
        cout<<endl;
        r++;
        int best = INT_MAX;
        for(int i=0;i<27;++i){
            for(int j=0;j<27;++j){
                if(best>dp[r][i][j]){
                    ansa=i;
                    best = dp[r][i][j];
                    ansb=j;
                }
            }
        }
    }
    return 0;
}    
