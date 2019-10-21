#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int MinStep(int a[], int n){
    int pos, neg, zero, step;
    pos = 0;
    neg = 0;
    zero = 0;
    step = 0;
    for(int i=0;i<n;++i){
        if(a[i]>0){
            pos++;
            step = step + (a[i] - 1);
        }
        else if(a[i] == 0){
            zero++;
        }
        else{
            step = step + (-1 - a[i]);
            neg++;
        }
    }
    cout<<pos<<" "<<neg<<" "<<zero<<" "<<step<< endl;
    if(neg%2==0){
        step += zero;
    }
    else{
        if(zero>0){
            step = step + zero;
        }
        else
            step = step + 2;
    }
    return step;
}
int main(){
    int a[] = { 0, -2, -1, -3, 4 }; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    cout << MinStep(a, n) << endl;     
    return 0;
}
