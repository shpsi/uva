#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define PI acos(-1.0)
#define EPS 1e-4
char a[3][3];
bool win(char x){
    for(int i=0;i<3;++i){
        if(a[i][0]==x && a[i][1]==x && a[i][2]==x)
            return true;
    }
    for(int i=0;i<3;++i){
        if(a[0][i]==x && a[1][i]==x && a[2][i]==x)
            return true;
    }
    if(a[0][0]==x && a[1][1]==x && a[2][2]==x)
        return true;
    if(a[0][2]==x && a[1][1]==x && a[2][0]==x)
        return true;
    return false;
}
int main(){
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            cin>>a[i][j];
    int cx = 0, co = 0;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(a[i][j]=='X')
                cx++;
            else if(a[i][j]=='0')
                co++;
        }
    }
    if(cx<co || (cx-co)>1 || (win('X') && win('0')))
        cout<<"illegal";
    else if(win('X') && cx==co)
        cout<<"illegal";
    else if(win('0') && co<cx)
        cout<<"illegal";
    else if(win('X'))
        cout << "the first player won";
	else if (win('0')) 
        cout << "the second player won";
    else if(cx+co==9)
        cout<<"draw";
    else if(cx>co)
        cout<<"second";
    else
        cout<<"first";
    return 0;
}    
