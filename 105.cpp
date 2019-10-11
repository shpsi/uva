#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> city;
    city.resize(20000*4);
    for(int i=0;i<=20000;++i)
        city[i] = 0;
    int l,h,r,rmax = -1;
    while(scanf("%d %d %d",&l,&h,&r) != EOF){
        for(int i=l;i<r;++i){
            city[i+500] = max(city[i+500],h);
        }
        rmax = max(r,rmax);
    }
    int i = 0;
    while(city[i] == 0)
        i++;
    while(true){
        cerr <<"in infinite loop"<<endl;
        cout<<i-500 <<" ";
        int curH = city[i];
        cout<<curH;
        while(city[i] == curH)
            i++;
        if(i > rmax + 500)
            break;
        cout<<" ";
    }
    cout<<endl;
    return 0;
}
