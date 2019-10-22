https://www.geeksforgeeks.org/find-the-number-of-p-sided-squares-in-a-grid-with-k-blacks-painted/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void CountSquares(int h, int w, int n, int k, int p, vector<pair<int, int > > painted){

}
int main(){
    int H = 4, W = 5, N = 8, K = 4, P = 3; 
    vector<pair<int, int> > painted; 
  
    // Initializing matrix 
    painted.push_back({ 3, 1 }); 
    painted.push_back({ 3, 2 }); 
    painted.push_back({ 3, 4 }); 
    painted.push_back({ 4, 4 }); 
    painted.push_back({ 1, 5 }); 
    painted.push_back({ 2, 3 }); 
    painted.push_back({ 1, 1 }); 
    painted.push_back({ 1, 4 }); 
  
    CountSquares(H, W, N, K, P, painted);    
    return 0;
}
