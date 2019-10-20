#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void genArr(vector<int> a){
    int n = a.size();
    int b[n];
    for(int i = 0; i < n; ++i){
        int cn = 0;
        for(int j = 0; j<i; ++j)
            if(a[j] % a[i] == 0)
                cn++;
        b[i] = cn;
    }
    for(int i = 0; i<n;++i)
        cout<<b[i]<<" ";
    cout<<endl;
}
int main(){
    vector<int> a;
    a.pb(3);
    a.pb(5);
    a.pb(1);
    genArr(a);
    return 0;
}
