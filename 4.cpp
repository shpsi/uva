#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int prodOfDig(int n){
    int ans = 1;
    while(n){
        ans *= n%10;
        n /= 10;

    }
    return ans;

}
int comp(int x, int y){
    int a, b;
    a = prodOfDig(x);
    b = prodOfDig(y);
    return a<b ? true : false;

}
int main(){
    vector<int> arr;
    arr.pb(12);
    arr.pb(10);
    arr.pb(102);
    arr.pb(31);
    arr.pb(15);
    sort(arr.begin(), arr.end(), comp);
    for(auto it : arr)
        cout << it << " ";
    cout << endl;
    return 0;

}
