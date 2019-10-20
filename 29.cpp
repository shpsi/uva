#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void checkAllOnes(int a[],int n,int k){
    int b[n];
    memset(b,0,sizeof(b));
    for(int i=0;i<n;++i){
        if(a[i] == 1){
            int h = k;
            int j=i;
            while(j>=0 && h){
                b[j] = 1;
                j--;
            }
            h=k;
            j=i+1;
            while(j<n && h){
                b[j]=1;
                j++;
            }
        }
    }
    bool flg=true;
    for(int i=0;i<n;++i)
        if(b[i]==0)
            flg = false;
    cout << flg<<endl;
}
int main(){
    int arr[] = { 1, 0, 1, 0 }; 
    int k = 2; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    checkAllOnes(arr, n, k);     
    return 0;
}
