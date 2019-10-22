#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int solution(vector<int> a, int x){
    int ans = INT_MAX;
    sort(a.begin(), a.end());
    for(int i=0;i<a.size();++i){
        int j=i+1;
        int k=a.size()-1;
        while(j<a.size() && k>i && j<k){
            int sum = a[i]+a[j]+a[k];
            if(abs(sum-x)<abs(ans-sum)){
                ans = sum;
            }
            if(sum>x){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> arr;
    arr.pb(-1);
    arr.pb(2);
    arr.pb(1);
    arr.pb(-4);
    int x = 1; 
    cout << solution(arr, x) << endl;    
    return 0;
}
