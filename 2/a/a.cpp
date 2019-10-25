#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string, int> mp1, mp2;
    int maxs=INT_MIN;
    string ans;
    vector<pair<string,int> > slist;
    while(n--){
        string s;
        int score;
        cin>>s>>score;
        slist.push_back(make_pair(s, score));
        mp1[s] += score;
    }
    for(auto it:mp1)
        maxs = max(maxs, it.second);
    for(int i=0;i<slist.size();++i){
        mp2[slist[i].first] += slist[i].second;
        if(mp1[slist[i].first] == maxs && mp2[slist[i].first] >= maxs){
            ans = slist[i].first;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}    
