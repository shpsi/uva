#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define MAX 15
int segtree[MAX];
int lazy[MAX];
void build(int a[], int curr, int l, int r){
    if(l==r){
        segtree[curr] = a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(a,2*curr,l ,mid);
    build(a,2*curr+1,mid+1,r);
    segtree[curr] = segtree[2*curr] + segtree[2*curr+1];
}
void update_tree(int curr, int cl, int cr, int ql, int qr){
    if(lazy[curr] != 0){
        segtree[curr] = -1 * segtree[curr];
        if(cl != cr){
            lazy[2*curr] = !lazy[2*curr];
            lazy[2*curr+1] = !lazy[2*curr+1];
        }
        lazy[curr] = 0;
    }
    if(ql>cr || qr<cl){
        return ;
    }
    if(ql<=cl && qr>=cr){
        segtree[curr] = -1 * segtree[curr];
        if(cl != cr){
            lazy[2*curr] = !lazy[2*curr];
            lazy[2*curr+1] = !lazy[2*curr+1];
        }
        return ;
    }
    int mid = (cl+cr)/2;
    update_tree(2*curr, cl, mid, ql, qr);
    update_tree(2*curr+1, mid+1, cr, ql, qr);
    segtree[curr] = segtree[2*curr] + segtree[2*curr+1];
}
int query_tree(int curr, int cl, int cr, int ql, int qr){
    if(cl > qr || cr < ql){
        return 0;
    }
    if(lazy[curr] != 0){
        segtree[curr] = -1 * segtree[curr];
        if(cl != cr){
            lazy[2*curr] = !lazy[2*curr];
            lazy[2*curr+1] = !lazy[2*curr+1];
        }
        lazy[curr] = 0;
    }
    if (cl >= ql && cr <= qr)
        return segtree[curr];
    int mid = (cl+cr)/2;
    return query_tree(2*curr,cl,mid,ql,qr)+query_tree(2*curr+1,mid+1,cr,ql,qr);
}
int main(){
    int arr[]={1,2,3,4,5}; 
  
    int n=sizeof(arr)/sizeof(arr[0]); 
  
    // Building segment tree 
    build(arr,1, 0, n - 1); 
  
    // Array is { 1, 2, 3, 4, 5 } 
    cout << query_tree(1, 0, n - 1, 0, 4) << endl; 
   
    // Flip range 0 to 4 
    update_tree(1, 0, n - 1, 0, 4); 
  
    // Array becomes { -1, -2, -3, -4, -5 } 
    cout << query_tree(1, 0, n - 1, 0, 4) << endl; 
   
    // Flip range 0 t0 2 
    update_tree(1, 0, n - 1, 0, 2); 
  
    // Array becomes { 1, 2, 3, -4, -5 } 
    cout << query_tree(1, 0, n - 1, 0, 4) << endl;    
    return 0;
}
