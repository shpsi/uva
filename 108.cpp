#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[101][101];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> a[i][j];
            if(i>0)
                a[i][j] += a[i-1][j];
            if(j>0)
                a[i][j] += a[i][j-1];
            if(i>0 && j>0)
                a[i][j] -= a[i-1][j-1];
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=i;k<n;++k){
                for(int l=j;l<n;++l){
                    int temp = a[k][l];
                    if(i>0)
                        temp -= a[i-1][l];
                    if(j>0)
                        temp -= a[k][j-1];
                    if(i>0 && j>0)
                        temp += a[i-1][j-1];
                    ans = max(ans, temp);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
