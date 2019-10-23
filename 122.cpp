#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int kthSmallest(int a[], int k, int n){
    int low = *min_element(a,a+n);
    int high = *max_element(a,a+n);
    while(low <= high){
        int mid = (low+high)/2;
        int countless = 0, countequal = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < mid)
                ++countless;
            else if (a[i] == mid)
                ++countequal;
        }
        if(countless<k && (countless+countequal)>k){
            return mid;
        }
        else if(countless>=k){
            high = mid-1;
        }
        else if(countless < k && countless + countequal < k){
            low = mid+1;
        }
    }
}
int main(){
    int arr[] = { 7, 10, 4, 3, 20, 15 }; 
    int n = sizeof(arr) / sizeof(int); 
    int k = 3; 
  
    cout << kthSmallest(arr, k, n) << endl;    
    return 0;
}
