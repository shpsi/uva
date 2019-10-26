#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define PI acos(-1.0)
#define EPS 1e-4
#define pii pair<int,int>
bool comp(pair<pii, int> a, pair<pii, int > b){
    if(a.first.first == b.first.first)
        return a.first.second < b.first.second;
    return a.first.first < b.first.first;
}
void print(int dp[], int par[], vector<pair<pii, int> > inp, int idx){
    if (idx == -1)
        return;
    print(dp, par, inp, par[idx]);
    cout << inp[idx].second + 1 << " ";
}
int main(){
    int n, w, h;
    vector<pair<pii, int> > inp;
    cin >> n >> w >> h;
    for(int i=0;i<n;++i){
        int x, y;
        cin >> x >> y;
        if(x <= w || y <= h)
            continue;
        inp.pb(make_pair(make_pair(x,y),i));
    }
    sort(inp.begin(), inp.end(), comp);
    int dp[5010], par[5010];
    for(int i=0;i<5005;++i){
        par[i] = -1;
        dp[i] = 1;
    }
    //cout<<dp[0]<<endl;
    for(int i=1;i<inp.size();++i){
        for(int j=0;j<i;++j){
            int x1, y1, x2, y2;
            x1 = inp[i].first.first;
            y1 = inp[i].first.second;
            x2 = inp[j].first.first;
            y2 = inp[j].first.second;
            if(x2<x1 && y2<y1){
                if(dp[j]+1>dp[i]){
                    dp[i] = dp[j] + 1;
                    par[i] = j;
                }
            }
        }
    }
    int mxv=-1, idx;
    for(int i=0;i<inp.size();++i){
        //cout<<dp[i]<<endl;
        if(dp[i]>mxv){
            mxv = dp[i];
            idx= i;
        }
    }
    if (mxv < 1)
        return cout << 0 , 0;
    cout << mxv << endl;
    print(dp, par, inp, idx);
    return 0;
}    
