#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
bool ispossible(int array[], int mid, int n, int K){
    int count=0;
    int sum=0;
    for (int i = 0; i < n; i++) {

        // If individual element is greater
        // maximum possible sum
        if (array[i] > mid)
            return false;

        // Increase sum of current sub - array
        sum += array[i];

        // If the sum is greater than
        // mid increase count
        if (sum > mid) {
            count++;
            sum = array[i];
        }
    }
    count++;

    // Check condition
    if (count <= K)
        return true;
    return false;
}
int solve(int a[], int n, int k){
    int sum=0;
    for(int i=0;i<n;++i)
        sum += a[i];
    int low=0;
    int high=sum;
    int ans=0;
    while(low <= high){
        int mid = (low+high)/2;
        if(ispossible(a,mid,n,k)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    int array[] = { 1, 2, 3, 4 }; 
    int n = sizeof(array) / sizeof(array[0]); 
    int K = 3; 
    cout << solve(array, n, K) << endl;    
    return 0;
}
