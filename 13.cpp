#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void findPair(vector<int> a){
    int n = a.size();
    int ma = *max_element(a.begin(), a.end());
    int middle = ma%2 ? ma/2+1 : ma/2;
    int diff = INT_MAX;
    int r;
    for(int i = 0; i < n; ++i){
        if(abs(middle - a[i]) < diff){
            diff = abs(middle - a[i]);
            r = i;
        }
    }
    cout << ma << " " << a[r] << endl;
}
int main(){
    vector<int> a;
    a.pb(0);
    a.pb(2);
    a.pb(3);
    a.pb(4);
    a.pb(1);
    a.pb(6);
    a.pb(8);
    a.pb(9);
    findPair(a);
    return 0;
}
