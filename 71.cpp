https://www.geeksforgeeks.org/minimize-the-sum-of-the-array-according-the-given-condition/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void findMin(int a[], int n){
    sort(a,a+n);
    int sum=0;
    for(int i=0;i<n;++i)
        sum += a[i];
    int max = 0;
    for(int i=n-1;i>=1;--i){
        
    }
}
int main(){
    int arr[] = { 1, 2, 3, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    findMin(arr, n);     
    return 0;
}
