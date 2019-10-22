#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void add(vector<int> adj[], int x, int y){
    adj[x].pb(y);
}
vector<int> topo(vector<int> adj[], int n){
    vector<int> indeg(n,0);
    for(int i=0;i<n;++i){
        for(int j=0;j<adj[i].size();++j){
            indeg[adj[i][j]]++;
        }
    }
    vector<int> ans;
    vector<int> vis(n,false);
    queue<int> bfs;
    for(int i=0;i<n;++i){
        if(indeg[i]==0){
            bfs.push(i);
            vis[i] = true;
        }
    }
    while(!bfs.empty()){
        int u = bfs.front();
        ans.pb(u);
        bfs.pop();
        for(int j=0;j<adj[u].size();++j){
            int v = adj[u][j];
            indeg[v]--;
            if(!vis[v] && indeg[v] == 0){
                bfs.push(v);
                vis[v] = true;
            }
        }
    }
    return ans;
}
int who_wins(vector<int> topotable, int u, int v)
{
    // Player who comes first wins
    for (auto x : topotable) {
        if (x == u)
            return u;
        if (x == v)
            return v;
    }
}

// Driver code
int main()
{
    vector<int> adj[10];

    // Total number of players
    int n = 7;

    // Build the graph
    // add(adj, x, y) means x wins over y
    add(adj, 0, 1);
    add(adj, 0, 2);
    add(adj, 0, 3);
    add(adj, 1, 5);
    add(adj, 2, 5);
    add(adj, 3, 4);
    add(adj, 4, 5);
    add(adj, 6, 0);

    // Resultant topological order in topotable
    vector<int> topotable = topo(adj, n);

    // Queries
    cout << who_wins(topotable, 3, 5) << endl;
    cout << who_wins(topotable, 1, 2) << endl;

    return 0;
}
