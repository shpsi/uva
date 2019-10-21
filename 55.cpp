#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define lg 63
struct TrieNode{
    int count;
    struct TrieNode* left;
    struct TrieNode* right;
};
TrieNode* getNewNode(){
    TrieNode* temp = new TrieNode();
    temp->left = nullptr;
    temp->right = nullptr;
    temp->count = 1;
    return temp;
}
void insert(TrieNode* root, int num, int &ans){
    for(int i=lg;i>=0;--i){
        int currBit = num & (1<<i);
        if(currBit == 0){
            if(root->left != nullptr){
                root = root->left;
                root->count++;
            }
            else{
                root->left = getNewNode();
                root = root->left;
            }
        }
        else{
            if(root->left != nullptr){
                ans += root->left->count;
            }
            if(root->right != nullptr){
                root = root->right;
                root->count++;
            }
            else{
                root->right = getNewNode();
                root = root->right;
            }
        }
    }
}
int getInvCount(int a[], int n){
    TrieNode* root = getNewNode();
    int ans = 0;
    for(int i=0;i<n;++i){
        insert(root,a[i],ans);
    }
    return ans;
}
int main(){
    int arr[] = { 8, 4, 2, 1 }; 
    int n = sizeof(arr) / sizeof(int); 
  
    cout << "Number of inversions are : "
         << getInvCount(arr, n) << endl;     
    return 0;
}
