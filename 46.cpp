#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
string getBin(int num){
    int binNum[32];
    int i=0;
    while(num){
        binNum[i] = num%2;
        num /= 2;
        i++;
    }
    string bin = "";
    for(int j=i-1;j>=0;--j)
        bin += to_string(binNum[j]);
    return bin;
}
int countOccur(string txt, string pat){
    int m = pat.length();
    int n = txt.length();
    int res = 0;
    for(int i=0;i<=n-m;++i){
        int j=0;
        for(;j<m;++j)
            if(pat[j] != txt[i+j])
                break;
        if(j==m){
            res++;
        }
    }
    return res;
}
void findOccurrence(int arr[], int n, string pattern){
    for(int i=0;i<n;++i){
        string bin = getBin(arr[i]);
        cerr << bin << endl;
        cout<< countOccur(bin, pattern) << endl;
    }
}
int main(){
    int arr[] = { 5, 106, 7, 8 }; 
    string pattern = "10"; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    findOccurrence(arr, n, pattern);
    return 0;
}
