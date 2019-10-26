#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define PI acos(-1.0)
#define EPS 1e-4
int main(){
    map<string,int>a;
    string s;
    cin>>s;
    while(cin>>s){
        if(a[s])
            cout<<s<<a[s]<<endl;
        else  
            cout<<"OK"<<endl;
        a[s]++;
    }
    return 0;
}    
