#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define maxn 10000
vector<int> segtree[maxn];
void build(int curr, int l, int r, pair<int,int> b[]){
    if(l==r){
        segtree[curr].pb(b[l].second);
        return ;
    }
    int mid = (l+r)/2;
    build(2*curr+1,l,mid,b);
    build(2*curr+2,mid+1,r,b);
    merge(segtree[2*curr+1].begin(), segtree[2*curr+1].end(),
          segtree[2*curr+2].begin(), segtree[2*curr+2].end(),
          back_inserter(segtree[curr]));
}
int query(int curr, int cl, int cr, int ql, int qr, int k){
    if(cl == cr){
        return segtree[curr][0];
    }
    int mid = (cl+cr)/2;
    int pos = upper_bound(segtree[2*curr+1].begin(),segtree[2*curr+1].end(),qr) - lower_bound(segtree[2*curr+1].begin(),segtree[2*curr+1].end(),ql);
    if (pos >= k) 
        return query(2 * curr + 1, cl, mid, ql, qr, k); 
    else
        return query(2 * curr + 2, mid + 1, cr, ql, qr, k - pos);
}
int main(){
    int arr[] = { 3, 1, 5, 2, 4, 7, 8, 6 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    pair<int, int> B[n]; 
  
    for (int i = 0; i < n; i++) { 
        B[i] = make_pair( arr[i], i ); 
    } 
  
    // After sorting, B's second property is 
    // something upon which we will build our Tree 
    sort(B, B + n); 
  
    // Build the tree 
    build(0, 0, n - 1, B); 
  
    cout << "3rd smallest element in range 3 to 7 is: "
         << arr[query(0, 0, n - 1, 2, 6, 3)] << "\n";    
    return 0;
}
