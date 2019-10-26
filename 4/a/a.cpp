#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define PI acos(-1.0)
#define EPS 1e-4
int main(){
    int n;
    cin>>n;
    if(n<=3){
        cout<<"NO";
    }
    else{
        if(n%2==0)
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}    
