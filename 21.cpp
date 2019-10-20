#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int findMin(vector<int> a){
    int sum=accumulate(a.begin(),a.end(),0);
    int n = a.size();
    int x = sum/n+1;
    return x;
}
int main(){
    vector<int>a;
    a.pb(4);
    a.pb(2);
    a.pb(1);
    a.pb(10);
    a.pb(6);
    cout<<findMin(a)<<endl;
    return 0;
}
