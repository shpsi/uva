#include<bits/stdc++.h>
using namespace std;
int R,C;
const int maxn = 102;
typedef long long ll;
ll table[maxn][maxn];
ll parent[maxn][maxn];
ll dp[maxn][maxn];
void print(ll r, ll c){
    if(c== C-1){
        cout<<" "<<r+1;
        return;
    }
    if(c == 0)
        cout<<r+1;
    else
        cout<<" "<<r+1;
    print(parent[r][c],c+1);
}
void free(){
    int i,j;
    for(i=0;i<R;++i)
        for(j=0;j<C;++j)
            dp[i][j] = 0;
}
ll recur(ll r, ll c){
    ll lastrow, currrow, nextrow, x, y, z, minc;
    if(c == C-1)
        return table[r][c];
    if(dp[r][c])
        return dp[r][c];
    dp[r][c] = 1;
    lastrow = (r + R - 1)%R;
    currrow = r;
    nextrow = (r + R + 1)%R;
    x = recur(lastrow,c+1);
    y = recur(currrow,c+1);
    z = recur(nextrow,c+1);
    minc = lastrow;
    if(x > y || (x == y && minc > currrow)){
        x = y;
        minc = currrow;
    }
    if(x > z || (x == z && minc > nextrow)){
        x = z;
        minc = nextrow;
    }
    table[r][c] += x;
    parent[r][c] = minc;
    return table[r][c];
}
void calculate(){
    ll i,min,d,f = 0;
    ll minr;
    for(int i=0;i<R;++i){
        d = recur(i,0);
        if(f++ == 0){
            min = d;
            minr = i;
        }
        else if(d < min){
            min = d;
            minr = i;
        }
    }
    if(C == 1) {
        cout<<minr+1<<endl;
        cout<<min<<endl;
        return;
    }
    print(minr,0);
    cout<<endl;
    cout<<min;
    cout<<endl;
}
int main(){
    int i, j;
    while(cin>>R>>C){
        for(i=0;i<R;++i){
            for(j=0;j<C;++j){
                cin >> table[i][j];
            }
        }
        calculate();
        free();
    }
    return 0;
}
