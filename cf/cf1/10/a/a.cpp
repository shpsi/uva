#include <bits/stdc++.h>
using namespace std;
struct parr{
    int x;
    int y;
}arr[125];
int main(){
    int n, p1, p2, p3, t1, t2;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2 ;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i].x >> arr[i].y ;
    }   
    for(int i = 1; i <= n; ++i){
        ans += (arr[i].y - arr[i].x) * p1;
        if(i + 1 > n)
            break;
        int diff = arr[i+1].x - arr[i].y;
        if(diff > t1){
            ans += t1 * p1;
            diff -= t1;
        }
        else{
            ans += diff * p1;
            diff = 0;
            continue;
        }
        if(diff > t2){
            ans += t2 * p2;
            diff -= t2;
        }
        else{
            ans += diff * p2;
            diff = 0;
            continue;
        }
        if(diff != 0){
            ans += diff * p3;
            diff = 0;
        }
    }
    cout << ans << endl;
    return 0;
} 
