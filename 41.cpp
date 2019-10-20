#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void performQueries(vector<int> arr,vector<pair<int,int> > q){
    int n = arr.size();
    int prx[n];
    memset(prx,0,n);
    for(int i=0;i<n;++i){
        if(i==0)
            prx[i]=arr[i];
        else
            prx[i] = prx[i-1]^arr[i];
    }
    for(auto query:q){
        int l, r;
        l = query.first;
        r = query.second;
        l--; r--;
        if(l > r){
            swap(l,r);
        }
        if(l !=r && prx[r] == prx[l - 1])
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}
int main(){
    vector<int> Arr; 
    Arr.pb(1);
    Arr.pb(1);
    Arr.pb(2);
    Arr.pb(2);
    Arr.pb(1);
    vector<pair<int, int> > q; 
    q.pb(make_pair(1,5));
    q.pb(make_pair(1,4));
    q.pb(make_pair(3,4));
    performQueries(Arr, q);    
    return 0;
}
