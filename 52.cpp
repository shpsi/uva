#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void findMaxSquare(int arr[], int n){
    map<int,int> mp;
    for(int i=0;i<n;++i)
        mp[arr[i]]++;
    int cnt=0,maxl =INT_MIN;
    for(auto it : mp){
        cerr << "debug:: "<< it.first <<" " << it.second << endl; 
        if(it.second>4 && it.first>maxl){
            maxl = it.first;
            cnt = it.second / 4;
        }   
    }
    cout << maxl*maxl << " " << cnt << endl;
}
int main(){
    int arr[] = { 2, 2, 2, 9, 2, 2, 2, 2, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    findMaxSquare(arr, n);     
    return 0;
}
