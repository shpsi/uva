#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string,int> mp;
    string s;
    for(int i=0;i<n;++i){
        cin >>s;
        mp[s]++;
    }
    int ans = 0;
    for(int i=0;i<n;++i){
        cin >> s;
        if(mp[s] > 0)
            mp[s]--;
        else
            ans++;
    }
    cout<<ans;
    return 0;
}    
