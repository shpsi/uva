#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int valueOfX(vector<int> a){
    int sum = accumulate(a.begin(), a.end(), 0);
    cerr << sum << endl;
    int n = a.size();
    if(sum % n == 0)
        return sum / n;
    int xx = sum / n;
    int yy = xx + 1;
    int xa = 0, xb = 0;
    for(int i = 0; i <= n; ++i){
        xa += (a[i] - xx) * (a[i] - xx);
        xb += (a[i] - yy) * (a[i] - yy);
    }
    return xa <= xb ? xx : yy;
}
int main(){
    vector<int> a;
    a.pb(6);
    a.pb(9);
    a.pb(1);
    a.pb(6);
    a.pb(1);
    a.pb(3);
    a.pb(7);
    cout << valueOfX(a) << endl;
    return 0;
}
