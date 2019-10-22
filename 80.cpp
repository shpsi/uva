#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int getSum(int bit[], int index){
    int sum=0;
    while(index>0){
        sum += bit[index];
        index -= (index & (-index));
    
    }
    return sum;
}
void update(int bit[], int n, int index, int val){
    while(index<=n){
        bit[index] += val;
        index += (index & (-index));
    }
}
void convert(int a[], int n){
    int temp[n];
    for(int i=0;i<n;++i)
        temp[i] = a[i];
    sort(temp, temp+n);
    for(int i=0;i<n;++i)
        a[i] = lower_bound(temp, temp+n, a[i]) - temp + 1;
}
int getCount(int arr[], int n){
    convert(arr,n);
    int smaller_right[n];
    int greater_left[n];
    int bit[n+1];
    for(int i=0;i<=n;++i)
        bit[i] = 0;
    for(int i=n-1;i>=0;--i){
        smaller_right[i] = getSum(bit, arr[i]-1);
        update(bit, n, arr[i], 1);
    }
    for(int i=0;i<=n;++i)
        bit[i] = 0;
    for(int i=0;i<n;++i){
        greater_left[i] = i - getSum(bit, arr[i]);
        update(bit,n, arr[i], 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += greater_left[i] * smaller_right[i];
    }

    // Return the required answer
    return ans;
}
int main(){
    int arr[] = { 7, 3, 4, 3, 3, 1}; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
      
    cout << getCount(arr, n) << endl;    
    return 0;
}
