#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int product(vector<int> a){
    int prod = 1;
    for(int i = 0; i < a.size(); ++i)
        prod *= a[i];
    int n = a.size();
    int p = pow(2,n-1);
    return pow(prod, p);
}
int main(){
    vector<int> a;
    a.pb(3);
    a.pb(7);
    cout << product(a) << endl;
    return 0;
}
