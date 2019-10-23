#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
bool compare(string s1, string s2){
    return s1.size() > s2.size();
}
bool can(string s, map<string, bool>& mp ){
    if(mp.find(s) != mp.end() && mp[s] == 0)
        return false;
    for(int i=1;i<s.length();++i){
        string left=s.substr(0,i);
        string right=s.substr(i+1);
        if(mp.find(left)!=mp.end() && mp[left] == 1 && can(right, mp)){
            mp[s] = 1;
            return true;
        }
    }
    mp[s] = 0;
    return false;
}
string printlongestword(vector<string> strlist){
    map<string,bool> mp;
    for(string s: strlist)
        mp[s] = true;
    sort(strlist.begin(), strlist.end(), compare);
    for(string s: strlist){
        if(can(s, mp))
            return s;
    }
    return "-1";
}
int main(){
    vector<string> listofwords ; 
    listofwords.pb("geeks");
    listofwords.pb("for");
    listofwords.pb("geeksfor");
    listofwords.pb("geeksforgeeks");
    cout << printlongestword(listofwords) << endl;     
    return 0;
}
