#include <bits/stdc++.h>
using namespace std;
#define INF 99999
int k, dp[1111][1111][2];
void print(int i, int j){
    //cout<<i<<" "<<j<<endl;
    if(i==1 && j==1){
        return;
    }
    else if(i>1 && j>1){
        if(dp[i-1][j][k]<dp[i][j-1][k]){
			print(i-1,j);
			cout<<('D');
		}
		else{
			print(i,j-1);
			cout<<('R');
		}
	}
	else if(i>1){
		print(i-1,j);
	    cout<<('D');
	}
	else if(j>1){
		print(i,j-1);
		cout<<('R');
	}
}
int main(){
    int n;
    cin>>n;
    bool flag = false;
    int pos = 0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int x;
            cin>>x;
            if(x==0){
                pos = i;
            }
            int c2=0;
            int c5=0;
            while(x>0 && x%2==0){
                c2++;
                x /= 2;
            }
            while(x>0 && x%5==0){
                c5++;
                x /= 5;
            }
            dp[i][j][0] = c2;
            dp[i][j][1] = c5;
            for(k=0;k<2;k++)
			{
				if(i>1 && j>1)
					dp[i][j][k]+=min(dp[i-1][j][k],dp[i][j-1][k]);
				else if(i>1)
					dp[i][j][k]+=dp[i-1][j][k];
				else if(j>1)
					dp[i][j][k]+=dp[i][j-1][k];
			}
        }
    }
    k=(dp[n][n][0] > dp[n][n][1]);
	if(pos && dp[n][n][k]>1)
	{
		cout<<"1\n";
		for(int i=1;i<pos;i++)
			putchar('D');
		for(int j=1;j<n;j++)
			putchar('R');
		for(int i=pos;i<n;i++)
			putchar('D');
        return 0;
    }
	cout<<dp[n][n][k]<<endl;
	print(n,n);
	cout<<endl;
    return 0;
}    
