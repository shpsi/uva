#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int sum(vector<int> a){
    int sum = accumulate(a.begin(), a.end(), 0);
    return sum*pow(2,a.size()-1);
}
int main(){
    vector<int> a;
    a.pb(2);
    a.pb(1);
    a.pb(5);
    a.pb(6);
    cout << sum(a) << endl;
    return 0;
}
