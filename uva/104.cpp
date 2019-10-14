#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        double best[20][20][20];
        int path[20][20][20];
        memset(best,0,sizeof(best));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i == j)
                    best[i][j][0] = 1.0;
                else
                    cin >> best[i][j][0];
            }
        }
        for(int steps = 1;steps<n;steps++){
            for(int k=0;k<n;++k){
                for(int i=0;i<n;++i){
                    for(int j=0;j<n;++j){
                        double temp = best[i][k][steps-1] * best[k][j][0];
                        if(temp > best[i][j][steps]){
                            best[i][j][steps] = temp;
                            path[i][j][steps] = k;
                        }
                    }
                }
            }
        }
        bool stat = false;
        for(int steps=0;steps<n;++steps){
            for(int i=0;i<n;++i){
                if(best[i][i][steps] > 1.0){
                    vector<int> seq;
                    seq.resize(steps);
                    seq[steps] = path[i][i][steps];
                    for(int j=steps-1;j>=0;--j){
                        seq[j] = path[i][seq[j+1]][j];
                    }
                    for(int j=0;j<=steps;++j)
                        cout<<seq[j] + 1 << " ";
                    cout<<seq[0] + 1 << endl;
                    stat = true;
                    break;
                }
            }
            if(stat)
                break;
        }
        if(!stat){
            cout << "no arbitrage sequence exists"<<endl;
        }
    }
    return 0;
}
