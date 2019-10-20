#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int mergeArrays(int* a, int n, int *b ,int m){
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i=0;i<m;++i)
        pq.push(b[i]);
    for(int i=0;i<n;++i){
        if(a[i]>pq.top()){
            int tmp = a[i];
            a[i] = pq.top();
            pq.pop();
            pq.push(tmp);
        }
    }
    int i=0;
    while(!pq.empty()){
        b[i] = pq.top();
        pq.pop();
        i++;
    }
}
int main(){
    int ar1[] = { 1, 5, 9, 10, 15, 20 }; 
    int ar2[] = { 2, 3, 8, 13 }; 
    int m = sizeof(ar1) / sizeof(ar1[0]); 
    int n = sizeof(ar2) / sizeof(ar2[0]); 
    mergeArrays(ar1, m, ar2, n); 
  
    cout << "After Merging :- \nFirst Array: "; 
    for (int i = 0; i < m; i++) 
        cout << ar1[i] << " "; 
    cout << "\nSecond Array: "; 
    for (int i = 0; i < n; i++) 
        cout << ar2[i] << " ";     
    return 0;
}
