#include<bits/stdc++.h>
using namespace std;
#define novalue -1
struct node{
    int val;
    node* left;
    node* right;
    node(){
        this->val = novalue;
        this->left = NULL;
        this->right = NULL;
    }
};
node* root;
int inputNodes = 0,nodes;
string path;
bool specified;
void insert(node* root,int &key, int pos){
    if(pos == path.size()){
        if(root->val != novalue)
            specified = false;
        root->val = key;
    }
    else if(path[pos] == 'L'){
        if(root->left == NULL){
            nodes++;
            node* temp = new node;
            root->left = temp;
            insert(temp,key,pos+1);
        }
        else{
            insert(root->left,key, pos+1);
        }
    }
    else{
        if(root->right == NULL){
            nodes++;
            node* temp = new node;
            root->right = temp;
            insert(temp,key, pos+1);
        }
        else{
            insert(root->right,key, pos+1);
        }
    }
}
void bfs(){
    queue<node*> q;
    q.push(root);
    vector<int> ans;
    node* currnode;
    while(!q.empty()){
        currnode = q.front();
        q.pop();
        ans.push_back(currnode->val);
        if(currnode->left != NULL)
            q.push(currnode->left);
        if(currnode->right != NULL)
            q.push(currnode->right);
    }
    for(int i=0;i<ans.size()-1;++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[ans.size()-1]);
}
void solve(){
    if(specified == false || inputNodes != nodes)
        puts("not complete");
    else
        bfs();
}
void clear(node* root){
    if(root == NULL)
        return ;
    clear(root->left);
    clear(root->right);
    delete root;
}
void init(){
    clear(root);
    root = new node;
    nodes = 1;
    specified = true;
    inputNodes = 0;
}
int main(){
    string s;
    int val;
    init();
    while(cin >> s){
        if(s=="()"){
            solve();
            init();
        }
        else{
            inputNodes++;
            stringstream ss;
            for(int i=0;i<s.size();++i){
                if(s[i] == '(' || s[i] == ')'|| s[i] == ',') 
                    s[i] = ' ';
            }
            ss << s;
            ss >> val;
            path = "";
            ss >> path;
            insert(root,val,0);
        }
    }
    return 0;
}
