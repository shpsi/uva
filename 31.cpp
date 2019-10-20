#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define maxn 1000
bool isPrime[maxn];
void initSeive(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i*i<=maxn;++i){
        if(isPrime[i]){
            for(int j=2*i;j<maxn;j+=i)
                isPrime[j] = false;
        }
    }
}
int gcd(int a, int b){
    return b==0 ? a : gcd(a,b%a);
}
int gcdPrimeFreq(vector<int> a){
    int n = a.size();
    map<int,int> mp;
    for(auto it:a){
        mp[it]++;
    }
    int totGcd = 1;
    for(auto it:mp){
        if(isPrime[it.second])
            totGcd = gcd(totGcd, it.first);
    }
    return totGcd;
}
int main(){
    vector<int> a;
    a.pb(5);
    a.pb(4);
    a.pb(6);
    a.pb(5);
    a.pb(4);
    a.pb(6);
    initSeive();
    cout<< gcdPrimeFreq(a)<<endl;
    return 0;
}
