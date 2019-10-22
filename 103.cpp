#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int pairs_count(int a[], int n, int sum){
    sort(a,a+n);
    int ans = 0;
    int i=0;
    int j=n-1;
    while(i<=j){
        if(a[i]+a[j]<sum){
            i++;
        }
        else if(a[i]+a[j]>sum){
            j--;
        }
        else{
            int x=i;
            int xx=a[i];
            while(i<n && a[i] == xx && i<=j){
                i++;
            }
            int y=j;
            int yy=a[j];
            while(j>=0 && a[j] == yy && i<=j)
                j--;
            if(i==j){
                int temp = i-x+y-j-1;
                ans += (temp*(temp+1))/2;
            }
            else{
                ans += (i-x)*(y-j);
            }
        }
    }
    return ans;
}
int main(){
    int arr[] = { 1, 5, 7, 5, -1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int sum = 6; 
  
    cout << pairs_count(arr, n, sum) << endl;    
    return 0;
}
