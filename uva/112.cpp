#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum;
bool yes;
char ch;
bool dfs(ll val){
    bool child1 = false, child2 = false;
    int currVal = 0, sign = 1;
    while(scanf("%c",&ch) != EOF){
        if(ch == ' ' && ch == '\n')
            continue;
        if(ch == ')')
            return false;
        if(ch == '(')
            break;
        if(ch == '-')
            sign = -1;
        if(isdigit(ch))
            currVal = currVal * 10 + (ch - 48);
    }
    currVal *= sign;
    val += (ll)currVal;
    child1 = dfs(val);
    while(scanf("%c",&ch) != EOF && ch =='(');
    child2 = dfs(val);
    if(!child1 && !child2 && val == sum)
        yes = true;
    while(scanf("%c",&ch) != EOF && ch != ')');
    return true;
}
int main(){
    char ch;
    while(scanf("%d",&sum) != EOF){
        yes = false;
        while(scanf("%c",&ch) != EOF && ch != '(');
        dfs(0);
        yes == true ? puts("yes") : puts("no");
    }
    return 0;
}
