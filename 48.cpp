#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int negProdSubArr(int arr[], int n){
    int pos, neg;
    pos = 0;
    neg = 0;
    int mult = 1;
    for(int i=0;i<n;++i){
        if(arr[i]>0)
            arr[i] = 1;
        else if(arr[i]<0)
            arr[i] = -1;
        mult *= arr[i];
        if(mult>0)
            pos++;
        else if(mult<0)
            neg++;
        cout << pos<<" "<<neg<<" "<< mult <<endl;
    }
    return pos * neg;
}
int main(){
    int arr[] = { 5, -4, -3, 2, -5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout << negProdSubArr(arr, n) << endl;     
    return 0;
}
