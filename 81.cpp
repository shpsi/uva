#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int findMissingPositive(int a[], int n){
    set<int> s;
    int exp = 1;
    for(int i=0;i<n;++i){
        s.insert(a[i]);
    }
    for(auto it:s){
        if(it==exp){
            exp++;
        }
        else if(it>exp){
            return exp;
        }
    }
    return exp;
}
int main(){
    int arr[] = { 2, 3, -7, 6, 8, 1, -10, 15 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function call 
    cout << findMissingPositive(arr, n) << endl;    
    return 0;
}
