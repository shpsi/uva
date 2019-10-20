#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define maxn 500
int lookup[maxn][maxn];
void initSparseTable(vector<int> a){
    int n = a.size();
    for(int i = 0; i < n; ++i)
        lookup[i][0] = a[i];
    for(int j = 1; (1 << j) <= n; ++j){
        for(int i = 0; i + (1 << j) <= n; ++i){
            lookup[i][j] = max(lookup[i][j-1],lookup[i + (1 << (j-1))][j-1]);
        }
    }
}
int query(int L, int R){
    int j = log2(R-L+1);
    return max(lookup[L][j], lookup[R-(1<<j)+1][j]);
}
int main(){
    vector<int> a;
    a.pb(7);
    a.pb(2);
    a.pb(3);
    a.pb(0);
    a.pb(5);
    a.pb(10);
    a.pb(3);
    a.pb(12);
    a.pb(18);
    initSparseTable(a);
    cout << query(0, 4) << endl;
    cout << query(4, 7) << endl;
    cout << query(7, 8) << endl;
    return 0;
}
