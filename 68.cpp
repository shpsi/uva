#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define maxn 10000
set<int>* segTree;
void build(int curr, int l, int r, int a[]){
    if(l==r){
        segTree[curr].insert(a[l]);
        return ;
    }
    build(curr*2,l,(l+r)/2,a);
    build(2*curr+1,(l+r)/2+1,r,a);
    segTree[curr].insert(segTree[2*curr].begin(), segTree[2*curr].end());
    segTree[curr].insert(segTree[2*curr+1].begin(), segTree[2*curr+1].end());
}
set<int> query(int curr, int cl, int cr, int ql, int qr){
    set<int> left, right, res;
    if(ql>cr || qr<cl){
        return res;
    }
    if(ql>=cl && qr<=cr)
        return segTree[curr];
    left = query(2*curr, cl, (cl+cr)/2, ql, qr);
    right = query(2*curr+1, (cl+cr)/2+1, cr, ql, qr);
    res.insert(left.begin(), left.end());
    res.insert(right.begin(), right.end());
    return res;
}
void init(int n){
    int h = (int)ceil(log2(n));
    h = (2*pow(2,h))-1;
    segTree = new set<int>[h];
}
int getDistinct(int l, int r, int n){
    cout << query(1,0,n-1,l,r).size()  << endl;
}
int main(){
    int arr[] = { 1, 1, 2, 1, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    init(n); 
  
    // Bulid the segment tree 
    build(1, 0, n - 1, arr); 
  
    // Query in range 0 to 4 
    getDistinct(0, 4, n);    
    return 0;
}
