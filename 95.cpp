#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int Removal(vector<int> a, int n){
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for(vector<int>::iterator i=a.begin();i!=a.end();++i){
        vector<int>::iterator j = upper_bound(a.begin(), a.end(), 2*(*i));
        ans = min(ans, n - (int)(j-i));
    }
    return ans;
}
int main(){
    vector<int> a;
    a.pb(4);
    a.pb(5);
    a.pb(100);
    a.pb(9);
    a.pb(10);
    a.pb(11);
    a.pb(12);
    a.pb(15);
    a.pb(200);
    int n = a.size(); 
  
    // Function call 
    cout << Removal(a, n) << endl;    
    return 0;
}
