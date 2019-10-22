#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int getSum(int bit[], int index){
    int sum = 0;
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
    sort(temp,temp+n);
    for(int i=0;i<n;++i)
        a[i] = lower_bound(temp,temp+n,a[i]) - temp + 1;
}
void findElements(int arr[], int n){
    convert(arr,n);
    int bit[n+1];
    for(int i=1;i<=n;++i){
        bit[i] = 0;
    }
    int smaller_right[n+1];
    int greater_left[n+1];
    for(int i=n-1;i>=0;--i){
        smaller_right[i] = getSum(bit, arr[i]-1);
        update(bit, n ,arr[i], 1);
    }
    cout << "Smaller right: ";

    // Print smaller_right array
    for (int i = 0; i < n; i++)
        cout << smaller_right[i] << " ";
    cout << endl;
    for(int i=1;i<=n;++i)
        bit[i]=0;
    for(int i=0;i<n;++i){
        greater_left[i] = i - getSum(bit, arr[i]-1);
        update(bit, n, arr[i], 1);
    }
    cout << "Greater left: ";

    // Print greater_left array
    for (int i = 0; i < n; i++)
        cout << greater_left[i] << " ";
}
int main(){
    int arr[] = { 12, 1, 2, 3, 0, 11, 4 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function call 
    findElements(arr, n);    
    return 0;
}
