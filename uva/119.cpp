#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, cant, candy;
    string s1,s2;
    vector<string> v;
    cin >> n;
    while(true){
        map<string,int> mp;
        v.clear();
        for(int i=0;i<n;++i){
            cin >> s1;
            v.push_back(s1);
        }
        for(int i=0;i<n;++i){
            cin >> s1 >> cant >> candy;
            if(candy!=0) mp[s1]-=candy*(cant/candy);
            for(int j=0;j<candy;j++){
                cin>>s2;
                mp[s2]+=cant/candy;
            }
        }
        for(int i=0;i<n;i++)
            cout<<v[i]<<" "<<mp[v[i]]<<endl;

        if(cin>>n) cout<<endl;
        else break;
    }
    return 0;
}
