#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define MAX 100000 
  
// Function to print the subsequence elements 
void print(int g1[], int a, int g2[], int b) 
{ 
  
    // Prints elements of the 1st subarray 
    for (int i = 0; i < a; i++) { 
        cout << g1[i] << " "; 
    } 
    cout << "and "; 
  
    // Prints elements of the 2nd subarray 
    for (int i = 0; i < b; i++) { 
        cout << g2[i] << " "; 
    } 
    cout << endl; 
}
bool checksum(int g1[], int a, int g2[], int b){
    int sum=0;
    for(int i=0;i<a;++i)
        sum += g1[i];
    for(int i=0;i<b;++i)
        sum -= g2[i];
    return sum == 0;
}
void formgroups(int arr[], int x, int g1[], int a, 
        int g2[], int b, int n){
    if(x==n){
        if(checksum(g1,a,g2,b)){
            print(g1,a,g2,b);
            return ;
        }
    }
    g1[a] = arr[x];
    formgroups(arr,x+1,g1,a+1,g2,b,n);
    g2[b] = arr[x];
    formgroups(arr,x+1,g1,a,g2,b+1,n);
}
int main(){
    int arr[] = { 1, 2, 3, 9, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    int g1[MAX], g2[MAX]; 
    formgroups(arr, 0, g1, 0, g2, 0, n);     
    return 0;
}
