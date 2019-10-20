#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int k;
bool comp(int a, int b){
    return a%k < b%k;
}
void sortWithRemainder(int arr[], int n,int k){
    sort(arr,arr+n,comp);
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int arr[] = { 10, 7, 2, 6, 12, 3, 33, 46 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    k = 4; 
    sortWithRemainder(arr, n, k);     
    return 0;
}
