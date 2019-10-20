#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define maxn 100001
int minHalls(vector<pair<int,int> > a){
    int n = a.size();
    int prefix[maxn];
    memset(prefix, 0 ,sizeof(prefix));
    for(int i=0;i<n;++i){
        prefix[a[i].first]++;
        prefix[a[i].second + 1]--;
    }
    int ans = prefix[0];
    for(int i=1;i<maxn;++i){
        prefix[i] += prefix[i-1];
        ans = max(ans, prefix[i]);
    }
    return ans;
}
int main(){
    vector<pair<int,int> > a;
    a.pb(make_pair(0,5));
    a.pb(make_pair(1,2));
    a.pb(make_pair(1,10));
    cout << minHalls(a) << endl;
    return 0;
}
