#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define PI acos(-1.0)
#define EPS 1e-4
int main(){
    char a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans = max(abs(a-c),abs(b-d));
    cout << ans << endl;
    if(ans != abs(a-c)){ // hori is min
        if(a<=c){
            if(b<=d){
                int cnt=0;
                for(int i=0;i<abs(a-c);++i)
                    cout<<"RU"<<endl,cnt++;
                for(int i=0;i<abs(b-d)-cnt;++i)
                    cout<<"U"<<endl;
            }
            else{
                int cnt=0;
                for(int i=0;i<abs(a-c);++i)
                    cout<<"RD"<<endl,cnt++;
                for(int i=0;i<abs(b-d)-cnt;++i)
                    cout<<"D"<<endl;
            }
        }
        else{
            if(b<=d){
                int cnt=0;
                for(int i=0;i<abs(a-c);++i)
                    cout<<"LU"<<endl,cnt++;
                for(int i=0;i<abs(b-d)-cnt;++i)
                    cout<<"U"<<endl;
            }
            else{
                int cnt=0;
                for(int i=0;i<abs(a-c);++i)
                    cout<<"LD"<<endl,cnt++;
                for(int i=0;i<abs(b-d)-cnt;i++)
                    cout<<"D"<<endl;
            }
        }
    }
    else{   // verti is min
        if(b<=d){
            if(a<=c){
                int cnt=0;
                for(int i=0;i<abs(b-d);++i)
                    cout<<"RU"<<endl,cnt++;
                for(int i=0;i<abs(a-c)-cnt;++i)
                    cout<<"R"<<endl;
            }
            else{
                int cnt=0;
                for(int i=0;i<abs(b-d);++i)
                    cout<<"LU"<<endl,cnt++;
                for(int i=0;i<abs(a-c)-cnt;++i)
                    cout<<"L"<<endl;
            }
        }
        else{
            if(a<=c){
                int cnt=0;
                for(int i=0;i<abs(b-d);++i)
                    cout<<"RD"<<endl,cnt++;
                for(int i=0;i<abs(a-c)-cnt;++i)
                    cout<<"R"<<endl;
            }
            else{
                int cnt=0;
                for(int i=0;i<abs(b-d);++i)
                    cout<<"LD"<<endl,cnt++;
                for(int i=0;i<abs(a-c)-cnt;++i)
                    cout<<"L"<<endl;
            }
        }
    }
    return 0;
}    
