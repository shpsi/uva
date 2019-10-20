#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define lg 31
struct TrieNode{
  TrieNode* children[2];
  int sumIdx;
  int numIdx;
  TrieNode(){
      this->children[0] = nullptr;
      this->children[1] = nullptr;
      this->sumIdx = 0;
      this->numIdx = 0;
  }
};
void insert(TrieNode* root, int num, int index){
    for(int i=lg; i >= 0; --i){
        int currBit = (num>>i)&1;
        if(root->children[currBit] == nullptr)
            root->children[currBit] = new TrieNode();
        root = root->children[currBit];
    }
    root->sumIdx += index;
    root->numIdx++;
}
int query(TrieNode * root, int preXor, int index){
    for(int i=lg; i >= 0; --i){
        int currBit = (preXor>>i)&1;
        if(root->children[currBit] == nullptr)
            return 0;
        root = root->children[currBit];
    }
    return index * root->numIdx - root->sumIdx;
}
int no_of_triplets(int arr[],int n){
    int preXor = 0;
    int ans = 0;
    TrieNode * root = new TrieNode();
    for(int i=0;i<n;++i){
        insert(root, preXor, i);
        preXor = preXor ^ arr[i];
        ans += query(root, preXor, i);
    }
    return ans;
}
int main(){
    int arr[] = { 5, 2, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << no_of_triplets(arr, n) << endl; 
    return 0;
}
