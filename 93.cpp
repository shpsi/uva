#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
void unique_combination(int l, int sum, int K, 
                        vector<int>& local, vector<int>& A) 
{ 
    if (sum == K) { 
        cout << "{"; 
        for (int i = 0; i < local.size(); i++) { 
            if (i != 0) 
                cout << " "; 
            cout << local[i]; 
            if (i != local.size() - 1) 
                cout << ", "; 
        } 
        cout << "}" << endl; 
        return; 
    } 
    for (int i = l; i < A.size(); i++) { 
        if (sum + A[i] > K) 
            break; 
        if (i and A[i] == A[i - 1] && i>l) 
            continue; 
        local.push_back(A[i]);
        unique_combination(i + 1, sum + A[i], K, local, A); 
        local.pop_back(); 
    } 
}
void Combination(vector<int> a, int k){
    sort(a.begin(), a.end());
    vector<int> temp;
    unique_combination(0, 0, k, temp, a);
}
int main(){
    vector<int> a;
    a.pb(10);
    a.pb(1);
    a.pb(2);
    a.pb(7);
    a.pb(6);
    a.pb(1);
    a.pb(5);
  
    int K = 8; 
  
    // Function call 
    Combination(a, K);    
    return 0;
}
