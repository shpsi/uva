#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
bool existsTriplet(int a[], int b[], int c[], int x, int l1, int l2, int l3){
    if(l2<=l1 && l2<=l3){
        swap(l2,l1);
        swap(a,b);
    }
    else if(l3<=l2 && l3<=l1){
        swap(l3,l1);
        swap(a,c);
    }
    for(int i=0;i<l1;++i){
        int j=0;
        int k=l3-1;
        while(j<l2 && k>=0){
            if(a[i]+a[j]+a[k]==x)
                return true;
            else if(a[i]+a[j]+a[k]<x){
                j++;
            }
            else{
                k--;
            }
        }
    }
    return false;
}
int main(){
    int a[] = { 2, 7, 8, 10, 15 }; 
    int b[] = { 1, 6, 7, 8 }; 
    int c[] = { 4, 5, 5 }; 
    int l1 = sizeof(a) / sizeof(int); 
    int l2 = sizeof(b) / sizeof(int); 
    int l3 = sizeof(c) / sizeof(int); 
  
    int x = 14; 
  
    if (existsTriplet(a, b, c, x, l1, l2, l3)) 
        cout << "Yes\n"; 
    else
        cout << "No\n";    
    return 0;
}
