#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void expressDigit(int a[], int n){
    int min=INT_MAX, minIdx;
    for(int i=0;i<n;++i){
        if(min>a[i]){
            minIdx=i;
            min=a[i];
        }
    }
    if(a[0]<min){
        cout<<1;
        for(int i=1;i<=a[0]+1;++i)
            cout<<0;
    }
    else{   
        for(int i=0;i<min;++i)
            cout<<minIdx;
        cout<<minIdx;
    }
    cout<<endl;
}
int main(){
    int arr[] = {2, 2, 1, 2, 1, 1, 3, 1, 1, 1}; 
      
    // Value of N is always 10 as we take digit from 0 to 9 
    int N = 10; 
      
    // Calling function 
    expressDigit(arr, N);    
    return 0;
}
