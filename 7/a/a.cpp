#include<iostream>
using namespace std;
int main(){
	char a[8][8];
	int flag[8]={0};
	int flag1[8]={0};
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			cin>>a[i][j];
		}
	}
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(a[i][j]=='B') flag[i]=1;
			else{
			flag[i]=0;
			break;	
			} 
		}
	}
	for(j=0;j<8;j++){
		for(i=0;i<8;i++){
			if(a[i][j]=='B') flag1[j]=1;
			else {
				flag1[j]=0;
				break;
			}
		}
	}
	int sum=0;
	for(i=0;i<8;i++){
		if(flag[i]==1) sum++;
	}
	for(i=0;i<8;i++){
		if(flag1[i]==1) sum++;
	}
	if(sum==16) cout<<"8\n";
	else cout<<sum<<endl;
	return 0;
} 
