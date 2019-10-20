#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define maxn 100
bool prime[maxn];
void seive(){
    memset(prime,true,maxn);
    prime[0] = false;
    prime[1] = false;
    for(int i=2;i*i<=maxn;++i){
        if(prime[i]){
            for(int j=2*i;j<maxn;j+=i)
                prime[j] = false;
        }
    }
}
void kMinXor(int arr[], int n, int k){
    priority_queue<int> pr, comp;
    for(int i=0;i<n;++i){
        if(prime[arr[i]]){
            if(pr.size()<k)
                pr.push(arr[i]);
            else{
                if(arr[i] < pr.top()){
                    pr.pop();
                    pr.push(arr[i]);
                }
            }
        }
        else if(arr[i] != -1){
            if(comp.size()<k)
                comp.push(arr[i]);
            else{
                if(arr[i] < comp.top()){
                    comp.pop();
                    comp.push(arr[i]);
                }
            }
        }
    }
    ll prXor = 0, compXor = 0;
    while(!pr.empty()){
        prXor = prXor ^ pr.top();
        pr.pop();
    }
    while(!comp.empty()){
        compXor = compXor ^ comp.top();
        comp.pop();
    }
    cout << prXor << " " << compXor << endl;
}
int main(){
    seive();    
    int arr[] = { 4, 2, 12, 13, 5, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    kMinXor(arr, n, k);
    return 0;
}
