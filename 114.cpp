#include<bits/stdc++.h>
using namespace std;
int xdir[] = {1,0,-1,0};
int ydir[] = {0,1,0,-1};
int main(){
    bool hasBumper[52][52];
    int bumperCost[52][52];
    int bumperScore[52][52];
    int X,Y;
    cin >>X>>Y;
    int wallCost,numBumper;
    cin >> wallCost >> numBumper ;
    for(int y=0;y<Y;++y){
        for(int x=0;x<X;++x){
            hasBumper[y][x] = false;
        }
    }
    while(numBumper--){
        int x,y;
        cin>>x>>y;
        --x;
        --y;
        hasBumper[y][x] = true;
        cin >> bumperScore[y][x] >> bumperCost[y][x];
    }
    int overallScore = 0;
    int bx,by,dir,lifetime;
    while(cin>>bx>>by>>dir>>lifetime){
        int score = 0;
        --bx;
        --by;
        while(--lifetime>0){
            int nx,ny;
            nx = bx + xdir[dir];
            ny = by + ydir[dir];
            if(nx <= 0 || nx >= X-1 || ny <= 0 || ny >= Y-1){
                lifetime -= wallCost;
                dir = (dir + 3)%4;
            }
            else if(hasBumper[ny][nx]){
                lifetime -= bumperCost[ny][nx];
                score += bumperScore[ny][nx];
                dir = (dir + 3)%4;
            }
            else{
                bx = nx;
                by = ny;
            }
        }
        cout << score << endl;
        overallScore += score;
    }
    cout<<overallScore<<endl;
    return 0;
}
