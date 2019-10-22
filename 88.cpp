#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int Next_greater(int a[], int n, int x){
    sort(a,a+n);
    int low = 0, high = n-1;
    int res = x+1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid]>res){
            high = mid-1;
        }
        else{
            if(a[mid] == res){
                res++;
                
            }
            low = mid+1;
        }
    }
    return res;
}
int main(){
    int a[] = { 1, 5, 10, 4, 7 }, x = 4; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    cout << Next_greater(a, n, x) << endl;    
    return 0;
}
