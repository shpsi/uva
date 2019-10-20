#include<bits/stdc++.h>
using namespace std;
int findProb(vector<int> a){
    int n = a.size();
    int maxSum = INT_MIN;
    int maxSumCnt = 0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(a[i] + a[j] > maxSum){
                maxSum = a[i] + a[j];
                maxSumCnt = 1;
            }
            else if(a[i] + a[j] == maxSum){
                maxSumCnt++;
            }
        }
    }
    int totPairs = n*(n-1)/2;
    cout << maxSumCnt*1.0 / totPairs << endl;
}
int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    cout << findProb(arr);
    return 0;
}
