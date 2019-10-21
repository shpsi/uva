#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int minimumDeletions(string s){
    map<char,int> mp;
    for(int i=0;i<s.length();++i)
        mp[s[i]-'a']++;
    map<int,int, greater<int> > mp2;
    for(auto it : mp){
        mp2[it.second]++;   
    }
    int ans = 0;
    for(auto it2=mp2.begin(); it2 != mp2.end(); it2++){
        if(it2->first == 0){
            continue;
        }
        else{
            //mp2[it2->first-1] += cnt;
            //mp2[it2->first] = 1;
            if(it2->second<=1)
                continue;
            int t1 = it2->second - 1;
            ans += t1;
            mp2[it2->first-1] += t1;
            it2->second = 1;
        }   
    }
    return ans;
}
int main(){
    string s = "geeksforgeeks"; 
    cout << minimumDeletions(s)<< endl;     
    return 0;
}
