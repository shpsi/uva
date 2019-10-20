#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
vector<int> findMissingEle(vector<int> a){
    int n = a.size();
    vector<int> missingEle;
    for(int i = 0; i < n; ++i){
        int num = abs(a[i]);
        int idx = num - 1;
        if(a[idx] > 0)
            a[idx] *= -1;
    }
    for(int i = 0; i < n; ++i)
        if(a[i] >= 0)
            missingEle.pb(i+1);
    return missingEle;
}
int main(){
    vector<int> a;
    a.pb(3);
    a.pb(3);
    a.pb(3);
    a.pb(5);
    a.pb(1);
    vector<int> missing_ele = findMissingEle(a);
    for(auto it: missing_ele)
        cout<<it<<" ";
    cout << endl;
    return 0;
}
