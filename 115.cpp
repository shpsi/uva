#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
struct circle{
    int st;
    int en;
};
bool compare(circle a, circle b){
    if(a.en == b.en)
        return a.st < b.st;
    return a.en < b.en;
}
void CountCircles(int c[], int r[], int n){
    circle a[n];
    for(int i=0;i<n;++i){
        a[i].st=c[i]-r[i];
        a[i].en=c[i]+r[i];
    }
    sort(a,a+n,compare);
    int ans = 0;
    int last = a[0].en;
    for(int i=1;i<n;++i){
        if(a[i].st > last){
            last = a[i].en;
        }
        else{
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int c[] = { 1, 2, 3, 4 }; 
    // radius of circles 
    int r[] = { 1, 1, 1, 1 }; 
  
    // number of circles 
    int n = sizeof(c) / sizeof(int); 
  
    CountCircles(c, r, n);    
    return 0;
}
