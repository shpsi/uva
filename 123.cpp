#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void compressArr(int a[], int n){
    int i,j;
    i=0;
    j=0;
    sort(a,a+n);
    while(i<n){
        j=i;
        while(j<n-1 && a[j]+1 == a[j+1])
            j++;
        if (i == j) {
            cout << a[i] << " ";
            i++;
        }
        else {
            cout << a[i] << "-" << a[j] << " ";
            i = j + 1;
        }
    }
}
int main(){
    int n = 7; 
    int arr[n];
    arr[0]=1;
    arr[1]=3;
    arr[2] =4;
    arr[3]=5;
    arr[4]=6;
    arr[5]=9;
    arr[6]=10 ; 
  
    compressArr(arr, n);    
    return 0;
}
