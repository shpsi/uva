#include<bits/stdc++.h>
using namespace std;
char dirs[] = {'N','E','S','W'};
int xdir[] = {0,1,0,-1};
int ydir[] = {1,0,-1,0};
int main(){
    int xs,ys;
    cin >>xs>>ys;
    vector<vector<bool> > scent(ys+1,vector<bool> (xs+1,false));
    int x, y;
    char stdir;
    string order;
    while(cin>>x>>y>>stdir>>order){
        int dir;
        for(int i=0;i<4;++i)
            if(stdir == dirs[i])
                dir = i;
        bool died = false;
        for(int i=0;i<order.size();++i){
            if(order[i] == 'R')
                dir = (dir+1)%4;
            else if(order[i] == 'L')
                dir = (dir+3)%4;
            else{
                if(x+xdir[dir] == -1 || x + xdir[dir] == xs+1 || y + ydir[dir] == -1 || y + ydir[dir] == ys+1){
                    if(!scent[y][x]){
                        scent[y][x] = true;
                        died = true;
                        break;
                    }
                }
                else{
                    x = x + xdir[dir];
                    y = y + ydir[dir];
                }
            }
        }
        cout << x << " "<<y<<" "<< dirs[dir] << (died ? " LOST" : "") << '\n';
    }
    return 0;
}
