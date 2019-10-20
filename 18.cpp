#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int no_of_ways(int a[], int n){
    int currXor = 0;
    for(int i=0;i<n;++i)
        currXor = currXor ^ a[i];
    int count = 0;
    for(int i=0;i<n;++i)
        if(a[i] == currXor)
            count++;
    return count;
}
int main(){
    int n = 4; 
    int a1[4] = { 1, 1, 0, 0 }; 
    cout << no_of_ways(a1, n) << endl; 
  
    n = 5; 
    int a2[5] = { 1, 1, 1, 0, 0 }; 
    cout << no_of_ways(a2, n) << endl; 
  
    n = 5; 
    int a3[5] = { 1, 1, 0, 0, 0 }; 
    cout << no_of_ways(a3, n) << endl; 
  
    n = 6; 
    int a4[6] = { 1, 1, 1, 0, 0, 0 }; 
    cout << no_of_ways(a4, n) << endl;     
    return 0;
}
