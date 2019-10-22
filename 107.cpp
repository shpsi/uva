#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
struct val { 
    int first; 
    int second; 
};
bool compare(struct val p1, struct val p2){
    if(p1.first != p2.first)
        return p1.first<p2.first;
    return p1.second<p2.second;
}
int maxChainLen(val p[], int n){
    sort(p, p+n, compare);
    int l=1;
    int ans=INT_MIN;
    for(int i=1;i<n;++i){
        if(p[i].first>p[i-1].second)
            l++;
        else
            l=1;
        ans=max(ans, l);
    }
    return ans;
}
int main(){
    val p[] = { { 5, 24 }, { 39, 60 },  
              { 15, 28 }, { 27, 40 }, { 50, 90 } }; 
  
    int n = sizeof(p) / sizeof(p[0]); 
  
    // Fucntion call 
    cout << maxChainLen(p, n) << endl;    
    return 0;
}
