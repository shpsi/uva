#include <bits/stdc++.h>
using namespace std;
int strtoint(string s){
    int num=0;
    int power=1;
    reverse(s.begin(), s.end());
    for(int i=0;i<s.length();++i){
        int pos = s[i]-'A'+1;
        int value = pos*power;
        num += value;
        power *= 26;
    }
    return num;
}
string inttostr(int num){
    string s="";
    while(num){
        int rem = num%26;
        if(rem==0){
            s += 'Z';
            num /= 26;
            num--;
        }
        else{
            s += rem + 'A' - 1;
            num /= 26;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}
int revNum(int num){
    int x=0;
    while(num){
        int dig = num%10;
        x=x*10+dig;
        num /= 10;
    }
    return x;
}
int main(){
    //cout<<inttostr(25)<<endl;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int len = s.length();
        int i=len-1;
        while(i>=0 && (s[i] < 'A' || s[i] > 'Z'))
            i--;
        while(i>=0 && s[i]>='A' && s[i]<='Z')
            i--;
        if(i<0){ // input is of form 'BC23'
            string temp = "";
            int j=0;
            while(s[j]>='A' && s[j]<='Z')
                temp += s[j++];
            int col = strtoint(temp);
            int row=0;
            while(j<len){
                row = row*10 + s[j]-'0';
                j++;
            }
            cout<<"R"<<row<<"C"<<col<<endl;
        }
        else{ // input is of from 'R23C55'
            int j=1;
            int row=0;
            while(s[j]>='0' && s[j]<='9'){
                row = row*10+s[j]-'0';
                j++;
            }
            j++;
            int col=0;
            while(j<len && s[j]>='0' && s[j]<='9'){
                col = col*10+s[j]-'0';
                j++;
            }
            string temp = inttostr(col);
            cout<<temp<<row<<endl;
        }
    }
    return 0;
}  
