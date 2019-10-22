#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define R 5
#define C 5
enum direction{
    east,
    west,
    north,
    south
};
void turnDir(enum direction & curr){
    switch(curr){
        case east:
            curr = south;
            break;
        case north:
            curr = east;
            break;
        case west:
            curr = north;
            break;
        case south:
            curr = west;
            break;
    }
}
pair<int,int> next(int i, int j, enum direction dir){
    switch(dir){
        case east:
            j++;
            break;
        case west:
            j--;
            break;
        case south:
            i++;
            break;
        case north:
            i--;
            break;
    }
    return make_pair(i,j);
}
bool isValid(int i, int j){
    if(i>=0 && i<R && j>=0 && j < C)
        return true;
    return false;
}
void printspiral(int arr[R][C]){
    int count=0;
    int vis[R][C];
    memset(vis,false,sizeof(vis));
    enum direction currDir = east;
    int i=0;
    int j=0;
    while(count < R*C){
        cout << arr[i][j] << " "; 
        vis[i][j] = true;
        count++;
        pair<int, int> p = next(i, j, currDir);
        if(!isValid(p.first, p.second)){
            turnDir(currDir);
            p = next(i,j,currDir);
        }
        else if(vis[p.first][p.second] == true){
            turnDir(currDir);
            p = next(i,j,currDir);
        }
        i = p.first;
        j = p.second;
    }
}
int main(){
    int arr[R][C]; 
  
    // Fill the matrix 
    int counter = 1; 
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            arr[i][j] = counter++; 
  
    // Print the spiral form 
    printspiral(arr);     
    return 0;
}
