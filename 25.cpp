#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int cntgloves(int arr[], int n){
    int count = 0;
    sort(arr,arr+n);
    int ans = 0;
    for(int i=0;i<n-1;){
        if(arr[i] == arr[i+1]){
            count++;
            i+=2;
        }
        else
            i++; 
    }
    return count;
}
int main(){
    int arr[] = { 6, 5, 2, 3, 5, 2, 2, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << cntgloves(arr, n) << endl;     
    return 0;
}
