#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void findPairs(int a[], int n, int k, int d){
    if(n<2*k){
        cout<<-1<<endl;
        return;
    }
    vector<pair<int,int> > ans;
    sort(a,a+n);
    for(int i=0;i<k;++i){
        if(a[n-k+1] - a[i] >= d){
            pair<int, int> p = make_pair(a[i], a[n - k + i]); 
            ans.push_back(p); 
        }
    }
    if (ans.size() < k) {
        cout << -1;
        return;
    }
    for(auto v:ans){
        cout << "(" << v.first << ", "
             << v.second << ")" << endl;
    }
}
int main(){
    int arr[] = { 4, 6, 10, 23, 14, 7, 2, 20, 9 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 4, d = 3; 
  
    findPairs(arr, n, k, d);     
    return 0;
}
