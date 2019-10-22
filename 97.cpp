#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void addEdge(vector<pair<int,int> >& edges, list<int>* tree, int u, int v){
    edges.pb(make_pair(u,v));
    tree[u].pb(v);
    tree[v].pb(u);
}
void dfs(list<int>*tree, int curr, int par, int dp[]){
    dp[curr] = 1;
    for(auto it:tree[curr]){
        if(it != par){
            dfs(tree,it,curr,dp);
            dp[curr] += dp[it];
        }
    }
}
int maximizeSum(int a[], vector<pair<int,int> > edges, list<int>* tree, int n){
    int dp[n+1];
    memset(dp, 0 ,sizeof(dp));
    dfs(tree, 1, 0, dp);
    sort(a,a+n-1);
    vector<int> ans;
    for(auto it:edges){
        int x = it.first;
        int y = it.second;
        int fir = min(dp[x], dp[y]);
        int sec = n -fir;
        ans.pb(fir*sec);
    }
    sort(ans.begin(), ans.end());
    int res=0;
    for (int i = 0; i < n - 1; i++) { 
        res += ans[i] * a[i]; 
    } 
    return res;
}
int main(){
    int n = 5; 
    vector<pair<int, int> > edges; 
  
    list<int>* tree = new list<int>[n + 1]; 
  
    // Add an edge 1-2 in the tree 
    addEdge(edges, tree, 1, 2); 
  
    // Add an edge 2-3 in the tree 
    addEdge(edges, tree, 1, 3); 
  
    // Add an edge 3-4 in the tree 
    addEdge(edges, tree, 3, 4); 
  
    // Add an edge 3-5 in the tree 
    addEdge(edges, tree, 3, 5); 
  
    // Array which gives the edges weight 
    // to be assigned 
    int a[] = { 6, 3, 1, 9, 3 }; 
  
    cout << maximizeSum(a, edges, tree, n) << endl;    
    return 0;
}
