https://www.geeksforgeeks.org/optimal-strategy-for-a-game-set-3/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int dp[3000][3000];
bool taken[3000][3000];
int maxScore(vector<int> a){
    int n = a.size();
    int totTurns = n;
    bool turn = tot
}
string getMoves(int n){

}
int main(){
    int ar[] = { 10, 80, 90, 30 }; 
    int arraySize = sizeof(ar) / sizeof(int); 
  
    vector<int> bags(ar, ar + arraySize); 
    int ans = maxScore(bags); 
  
    cout << ans << " " << getMoves(bags.size()) << endl; 
    return 0;
}
