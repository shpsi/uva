#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
bool isDivisible(int a[], int x, int y){
    int rem = 0;
    int i=0;
    while(i<x){
        while(rem<y && i<x)
            rem = rem*10+a[i],i++;
        rem %= y;
    }
    return rem==0;
}
int main(){
    int arr[] = { 1, 2, 1, 5, 6 }; 
    int x = sizeof(arr) / sizeof(int); 
    int y = 4; 
  
    cout << (isDivisible(arr, x, y) ? "Yes" : "No");    
    return 0;
}
