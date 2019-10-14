#include<bits/stdc++.h>
using namespace std;
int main(){
    while(true){
        int num_of_boxes;
        cin >> num_of_boxes;
        if (cin.eof())
        {
            break;
        }
        int dimension;
        cin >> dimension;
        vector<vector<int> > boxes;
        boxes.resize(num_of_boxes);
        for(int i=0;i<num_of_boxes;++i){
            boxes[i].resize(dimension);
            for(int d=0;d<dimension;++d){
                cin >>boxes[i][d];
            }
        }
        for(int i=0;i<num_of_boxes;++i){
            sort(boxes[i].begin(),boxes[i].end());
        }
        vector<vector<int> > adjlist;
        adjlist.resize(num_of_boxes);
        vector<int> indegree;
        indegree.resize(num_of_boxes);
        for(int i=0;i<num_of_boxes;++i)
            indegree[i]=0;
        for(int i=0;i<num_of_boxes;++i){
            for(int j=i+1;j<num_of_boxes;++j){
                int gcomp = 2;
                for(int d=0;d<dimension;++d){
                    int localcomp;
                    if(boxes[i][d] == boxes[j][d])
                        localcomp = 0;
                    else if(boxes[i][d] > boxes[j][d])
                        localcomp = 1;
                    else
                        localcomp = -1;
                    if(gcomp == 2)
                        gcomp = localcomp;
                    else if(gcomp != localcomp){
                        gcomp = 0;
                        break;
                    }
                }
                if(gcomp == 1){
                    adjlist[i].push_back(j);
                    indegree[j]++;
                }
                else if(gcomp == -1){
                    adjlist[j].push_back(i);
                    indegree[i]++;
                }
            }
        }
        queue<int> bfsq;
        for(int i=0;i<num_of_boxes;++i){
            if(indegree[i] == 0)
                bfsq.push(i);
        }
        vector<int> topo;
        while(!bfsq.empty()){
            int currNode = bfsq.front();
            bfsq.pop();
            topo.push_back(currNode);
            for(vector<int>::iterator it=adjlist[currNode].begin();it!=adjlist[currNode].end();++it){
                int v = *it;
                indegree[v]--;
                if(indegree[v] == 0)
                    bfsq.push(v);
            }
        }
        vector<int> dp;
        vector<int> par;
        dp.resize(num_of_boxes);
        par.resize(num_of_boxes);
        dp[0] = 1;
        par[0] = -1;
        for(int i=1;i<num_of_boxes;++i){
            int best_len = 1, best_par = -1;
            for(int j=0;j<i;++j){
                if(find(adjlist[topo[j]].begin(),adjlist[topo[j]].end(),topo[i]) != adjlist[topo[j]].end()){
                    int temp = dp[j]+1;
                    if(temp > best_len){
                        best_len = temp;
                        best_par = j;
                    }
                }
            }
            dp[i] = best_len;
            par[i] = best_par;
        }
        int bestest_len = 1, bestest_par = -1;
        for(int i=0;i<num_of_boxes;++i){
            if(dp[i] > bestest_len){
                bestest_len = dp[i];
                bestest_par = i;
            }
        }
        cout<<bestest_len<<endl;
        while(bestest_par != -1){
            cout<< topo[bestest_par] + 1;
            bestest_par = par[bestest_par];
            if(bestest_par != -1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
