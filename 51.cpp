#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
bool change(int x,int y){
    int cnt = 0;
    while(x && y){
        if(x%10 != y%10)
            cnt++;
        x /= 10;
        y /= 10;
    }
    if(cnt == 1 && x==0 && y==0)
        return true;
    return false;
}
int getChange(int num, int l, int r){
    for(int i=l;i<=r;++i){
        if(change(i,num))
            return i;
    }
}
void getList(int arr[], int n){
    int last = 1000;
    for(int i=0;i<n;++i){
        last = getChange(arr[i],last,9999);
        cout<<last<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = { 1095, 1094, 1095 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    getList(arr, n); // 1005 1014 1015    
    return 0;
}
