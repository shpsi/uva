#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void printIt(vector<int> a){
    static int i = 0;
    if(i == a.size()){
        cout << endl;
        return;
    }
    cout << a[i] <<" ";
    i++;
    printIt(a);
}
int main(){
    vector<int> a;
    a.pb(5);
    a.pb(4);
    a.pb(1);
    a.pb(2);
    a.pb(3);
    printIt(a);
    return 0;
}
