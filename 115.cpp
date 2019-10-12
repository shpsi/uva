#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
const int maxn = 205;
unordered_map<string,int> str_num;
vector<string > num_str;
int n = 0;
vector<vector<int> > adjlist;
class LCA{
    int len, table[maxn][maxn], level[maxn];
    bitset<maxn> visited;
    void dfs(int u){
        visited[u] = true;
        for(auto& v: adjlist[u]){
            table[v][0] = u;
            if(!visited[v])
                dfs(v);
        }
    }
    void tableFiller(){
        visited.reset();
        for(int i=0;i<len;++i){
            if(!visited[i])
                dfs(i);
        }
        for(int j=1;(1<<j)<len;++j){
            for(int i=0;i<len;++i){
                if(table[i][j-1] != -1){
                    table[i][j] = table[table[i][j-1]][j-1];
                }
            }
        }
    }
    void fill_level(int u){
        visited[u] = true;
        for(auto& v: adjlist[u]){
            level[v] = level[u] + 1;
            fill_level(v);
        }
    }
    void leveler(){
        visited.reset();
        for(int i=0;i<len;++i){
            if(table[i][0] == -1){
                level[i] = 0;
                fill_level(i);
            }
        }
    }
public:
    LCA(int len){
        this->len = len;
        for(int i=0;i<maxn;++i){
            for(int j=0;j<maxn;++j)
                table[i][j] = -1;
        }
        tableFiller();
        leveler();
    }
    int get_lca(int a,int b){
        if(level[a] < level[b]) 
            swap(a,b);
        for(int i = log2(maxn); i >= 0; --i)
            if(level[a] - (1<<i) >= level[b])
                a = table[a][i];
        for(int i = log2(n); i>=0; --i)
            if(table[a][i] != -1 && table[a][i] != table[b][i])
                a = table[a][i], b = table[b][i];
        if(a == b)
            return a;
        return table[a][0];
    }
    int get_level(int x){
        return level[x];
    }
};
void mapStrToNum(string x){
    if(str_num.find(x) == str_num.end()){
        str_num[x] = n++;
        num_str.push_back(x);
    }
}
int marked[maxn] = {0};
void markIt(int u,int mark){
    marked[u] = mark;
    for(auto& v: adjlist[u]){
        markIt(v,mark);
    }
}
int main(){
    string str1, str2;
    adjlist.resize(305);
    while(cin >> str1 >> str2, str1 != "no.child"){
        mapStrToNum(str1);
        mapStrToNum(str2);
        adjlist[str_num[str2]].push_back(str_num[str1]);
    }
    int totalNodes = num_str.size();
    adjlist.resize(totalNodes);
    LCA lca(totalNodes);
    int mark = 0;
    for(int i = 0; i< totalNodes; ++i){
        if(!marked[i])
            markIt(i,++mark);
    }
    while(cin>>str1>>str2){
        if(str_num.find(str1) == str_num.end() || str_num.find(str2) == str_num.end()){
            cout<<"no relation"<<endl;
            continue;
        }
        int a = str_num[str1];
        int b = str_num[str2];
        if(marked[a] == marked[b]){
            int ancestor = lca.get_lca(a,b);
            int level_a = lca.get_level(a);
            int level_b = lca.get_level(b);
            if(ancestor == a || ancestor == b){
                int level_diff = abs(level_a - level_b);
                while(level_diff > 2){
                    cout<<"great ";
                    --level_diff;
                }
                if(level_diff > 1)
                    cout<<"grant ";
                if(level_a>level_b)
                    cout<<"child"<<endl;
                else
                    cout<<"parent"<<endl;
            }
            else{
                int csn = min(level_a, level_b) - lca.get_level(ancestor) - 1;
                int rmv = abs(level_a - level_b);

                if(csn == 0 && rmv == 0) cout << "sibling";
                else {
                    cout << csn << " cousin";
                    if(rmv) cout << " removed " << rmv;
                }

                cout << '\n';
            }
        }
        else{
            cout<<"no relation" <<endl;
        }
    }
    return 0;
}
