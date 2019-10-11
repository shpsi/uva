#include<bits/stdc++.h>
using namespace std;
int f(int n){
    int cnt = 1;
    while(n>1){
        n = n%2==1 ? 3*n+1 : n/2;
        cnt++;
    }
    return cnt;
}
int main(){
    int a,b;
    while((scanf("%d %d",&a,&b)) == 2){
        int aa=a;
        int bb=b;
        int t;
        if(a>b){t=a;a=b;b=t;}
        //cerr << a << " "<<b<<endl;
        int cnt_mx = -1;
        for(int i=a;i<=b;++i){
            int fx = f(i);
            //cerr << fx<<endl;
            if(fx > cnt_mx)
                cnt_mx = fx;
        }
        cout<<aa<<" "<<bb<<" "<< cnt_mx << endl;
    }
    return 0;
}
