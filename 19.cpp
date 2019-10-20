#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int FindRatio(int a,int b,int c){
    int up = abs(b-c);
    int down = abs(c-a);
    int gc = gcd(up,down);
    up /= gc;
    down /= gc;
    cout <<up << ":" << down<<endl;
}
int main(){
    int a = 4, b = 10, c = 6; 
  
    FindRatio(a, b, c);     
    return 0;
}
