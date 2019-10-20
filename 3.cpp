#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int findMissing(vector<int> arr,int avg, int k){
    int n = arr.size();
    int sum = 0;
    sum = accumulate(arr.begin(),arr.end(),sum);
    cerr << sum << endl;
    int num = (avg * (n+k)) - sum;
    cerr << num << endl;
    if(num % k != 0)
        return -1;
    return num / k;
}
int main(){
    int k = 3, avg = 4;
    vector<int> arr;
    arr.pb(2);
    arr.pb(7);
    arr.pb(3);
    cout << findMissing(arr, avg, k) << endl;
    return 0;
}
