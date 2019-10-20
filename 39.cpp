#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void rotate(deque<int> v, int d, int n){
    for(int i=0;i<d;++i){
        int tmp = v.back();
        v.pop_back();
        v.push_front(tmp);
    }
    for(int i=0;i<n;++i)
        cout<<v[i]<<" ";
    cout<<endl;
}
int main(){
    deque<int> v ; 
    v.pb(1);
    v.pb(2);
    v.pb(3);
    v.pb(4);
    v.pb(5);
    v.pb(6);
    v.pb(7);
    int n = v.size(); 
    int d = 5; 
  
    rotate(v, d % n, n);     
    return 0;
}
