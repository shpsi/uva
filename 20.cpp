#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int countPairs(vector<int> arr, int n){
    map<int,int> mp;
    for(int i=0;i<n;++i){
        cerr <<arr[i] - i << endl;
        if(mp.find(arr[i]-i)==mp.end())
            mp[arr[i]-i] = 1;
        else
            mp[arr[i]-i]++;
    }
    int sum = 0;
    for(auto it: mp){
        int cnt = it.second;
        cerr << cnt <<endl;
        sum += cnt*(cnt-1)/2;
    }
    return sum;
}
int main(){
    vector<int> arr;
    arr.pb(1);
    arr.pb(5);
    arr.pb(6);
    arr.pb(7);
    arr.pb(9);
    int n = arr.size(); 
    cout << countPairs(arr, n) <<"\n";    
    return 0;
}
