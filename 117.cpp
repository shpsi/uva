#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
}
void swapIt(int * a, int target, int src){
    for(int i=src;i>target;--i){
        int t=a[i];
        a[i]=a[i-1];
        a[i-1]=t;
    }
}
void maximizeArray(int a[], int n, int k){
    for(int i=0;i<n;++i){
        int maxIdx,max=INT_MIN;
        int lim = (k+i)>n?n:(k+i);
        for(int j=i;j<=lim;++j){
            if(a[j]>max){
                max=a[j];
                maxIdx=j;
            }
        }
        swapIt(a, i, maxIdx);
        k -= (maxIdx-i);
        if(k==0)
            return;
    }
}
int main(){
    int arr[] = { 1, 2, 9, 8, 1, 4, 9, 9, 9 }; 
    int length = sizeof(arr) / sizeof(int); 
    int swaps = 4; 
    maximizeArray(arr, length, swaps); 
  
    print(arr, length);    
    return 0;
}
