#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int findSubarray(int arr[], int n){
    map<int, int > mp;
    int prx = 0;
    int ans = 0;
    mp[0]=1;
    for(int i=0;i<n;++i){
        prx = prx ^ arr[i];
        for(int j=0;j<=10;++j){
            int value = (int)pow(2,j);
            int subXor = prx ^ value;
            if(mp.find(subXor) != mp.end()){
                ans += mp[subXor];
            }
        }
        mp[prx]++;
    }
    return ans;
}
int main(){
    int array[] = { 2, 6, 7, 5, 8 }; 
      
    int n = sizeof(array) / sizeof(array[0]); 
      
    cout << findSubarray(array, n) << endl;     
    return 0;
}
