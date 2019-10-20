#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
bool isPossible(int A[], int B[], int n, int m, int x, int y){
    if(x>n || y>m)
        return false;
    sort(A,A+n);
    sort(B,B+m);
    if(A[x-1] < B[m-y])
        return true;
    return false;
}
int main(){
    int A[] = { 1, 1, 1, 1, 1 }; 
    int B[] = { 2, 2 }; 
    int n = sizeof(A) / sizeof(int); 
    int m = sizeof(B) / sizeof(int); 
    int x = 3, y = 1; 
  
    if (isPossible(A, B, n, m, x, y)) 
        cout << "Yes"; 
    else
        cout << "No";    
    return 0;
}
