#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int longestAlternativeSequence(int a[], int n){
    int maxi1 = 0;
    int f1=0;
    for(int i=0;i<n;++i){
        if(f1){
            if(a[i]%2==0){
                maxi1++;
                f1=0;
            }
        }
        else{
            if(a[i]%2==1){
                maxi1++;
                f1=1;
            }
        }
    }
    int maxi2=0;
    int f2=0;
    for(int i=0;i<n;++i){
        if(f2){
            if(a[i]%2==1){
                maxi2++;
                f2=0;
            }
        }
        else{
            if(a[i]%2==0){
                maxi2++;
                f2=1;
            }
        }
    }
    return max(maxi1, maxi2);
}
int main(){
    int a[] = { 13, 16, 8, 9, 32, 10 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << longestAlternativeSequence(a, n) << endl;    
    return 0;
}
