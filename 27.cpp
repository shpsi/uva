#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define maxn 10
int fact[maxn];
void init(){
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=maxn;++i)
        fact[i] = i*fact[i-1];
}
bool isFactorion(int n){
    int nc = n;
    int sum=0;
    while(n){
        sum += fact[n%10];
        n /= 10;
    }
    return sum == nc;
}
int main(){
    init();
    int n = 40585;
    if (isFactorion(n))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
