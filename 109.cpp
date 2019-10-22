#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
vector<int> findCount(string a[], string b[], int n, int m){
    int freq[26];
    vector<int> smallfreq1;
    for(int i=0;i<n;++i){
        string x = a[i];
        memset(freq,0,sizeof(freq));
        for(int j=0;j<x.length();++j)
            freq[x[j]-'a']++;
        for(int j=0;j<26;++j){
            if(freq[j]){
                smallfreq1.pb(freq[j]);
                break;
            }
        }
    }
    sort(smallfreq1.begin(), smallfreq1.end());
    vector<int> ans;
    for(int i=0;i<m;++i){
        string s = b[i];
        memset(freq, 0, sizeof freq); 
        for (int j = 0; j < s.size(); j++) { 
            freq[s[j] - 'a']++; 
        } 
        int frequency = 0; 
        for (int j = 0; j < 26; j++) { 
            if (freq[j]) { 
                frequency = freq[j]; 
                break; 
            } 
        }
        int ind = lower_bound(smallfreq1.begin(), smallfreq1.end(), frequency) - smallfreq1.begin();
        ans.pb(ind);
    }
    return ans;
}
void printAnswer(string a[], string b[], int n, int m)
{

    // Get the answer
    vector<int> ans = findCount(a, b, n, m);

    // Print the number of strings
    // for every answer
    for (auto it : ans) {
        cout << it << " ";
    }
}

// Driver code
int main()
{
    string A[] = { "aaa", "aa", "bdc" };
    string B[] = { "cccch", "cccd" };
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    printAnswer(A, B, n, m);

    return 0;
}
