#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void findPair(vector<int> a){
    int fm, sm;
    fm = -1;
    sm = -1;
    for(int i=0;i<a.size();++i){
        if(fm == -1){
            fm = a[i];
            continue;
        }
        else if(sm == -1){
            sm = a[i];
            continue;
        }
        else{
            if(a[i] > fm){
                sm = fm;
                fm = a[i];
            }
            else if(a[i] > sm){
                sm = a[i];
            }
        }
    }
    cout<<fm<<" "<<sm<<endl;
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
