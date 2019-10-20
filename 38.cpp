#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
vector<vector<int> > gr;
vector<vector<int> > freq;
void add_edge(int u, int v){
    gr[u].pb(v);
    gr[v].pb(u);
}
int djkstra(int n){
    int vis[n], dist[n];
    memset(vis,-1,n);
    memset(dist,INT_MAX,n);
    queue<int> bfsq;
    bfsq.push(0);
    vis[0] = 1;
    dist[0] = 0;
    while(!bfsq.empty()){
        int curr = bfsq.front();
        bfsq.pop();
        for(int i=0;i<gr[curr].size();++i){
            int nxt = gr[curr][i];
            if(vis[nxt] == 1){
                continue;
            }
            vis[nxt] = 1;
            bfsq.push(nxt);
            dist[nxt] = dist[curr] + 1;
        }
    }
    return dist[n-1];
}
int Min_Moves(int arr[], int n){
    gr.resize(n);
    freq.resize(10);
    for(int i=0;i<n;++i){
        if(i != n-1)
            add_edge(i,i+1);
        freq[arr[i]].pb(i);
    }
    for(int i=0;i<10;++i){
        for(int j=0;j<freq[i].size();++j){
            for(int k=j+1;k<freq[i].size();++k)
                if(abs(freq[i][j]-freq[i][k]) != 1)
                    add_edge(freq[i][j],freq[i][k]);
        }
    }
    return djkstra(n);
}
int main(){
    int a[] = { 1, 2, 3, 4, 1, 5 }; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    cout << Min_Moves(a, n) << endl; 
      
    return 0;
}
