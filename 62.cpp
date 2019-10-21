#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void findMajority(int a[], int n){
    int num = 0;
    for(int i=0;i<32;++i){
        int cnt=0;
        for(int j=0;j<n;++j){
            if(a[j] & (1<<i))
                cnt++;
        }
        if(cnt> (n/2))
            num |= (1<<i);
    }
    int  count=0;
    for(int i=0;i<n;++i)
        if(a[i] == num)
            count++;
    if (count > (n / 2)) 
        cout << num; 
    else
        cout << "Majority Element Not Present";
}
int main(){
    int arr[] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    findMajority(arr, n); 
    return 0;
}
