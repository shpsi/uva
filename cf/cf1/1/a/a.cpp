#include <bits/stdc++.h>
using namespace std;
int main(){
    double n,m,a;
    cin >> n >> m >> a;
    double l = ceil(n/a);
    double w = ceil(m/a);
    long long ans = l * w;
    cout << ans << endl;
    return 0;
}    
