#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s[0] == 'R'&&s[1] >= '0'&&s[1] <= '9'&&s.find('C') != s.npos){
            auto cpos = s.find('C');
            int r = atoi(s.substr(1,cpos-1).c_str());
            int c = atoi(s.substr(cpos+1).c_str());
            string a = "";
            while(c > 0){
                c--;
                a += char(c%26 + 'A');
                c /= 26;
            }
            reverse(a.begin(),a.end());
            cout << a << r << endl;
        }
        else{
            int c = 0;
            int idx = 0;
            while(s[idx] < '0' || s[idx] > '9'){
                c = c*26 + s[idx] - 'A' + 1;
                idx++;
            }
            cout << "R" << s.substr(idx) << "C" << c << endl; 
        }
    }
    return 0;
}    
