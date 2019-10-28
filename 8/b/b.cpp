#include<bits/stdc++.h>
using namespace std;
int mp[205][205];
int main()
{
	char c;
	int x=100,y=100;
	while(cin>>c)
	{
		++mp[x-1][y];
		++mp[x+1][y];
		++mp[x][y-1];
		++mp[x][y+1];
		if(c=='L') x--;
		if(c=='R') x++;
		if(c=='U') y++;
		else if(c=='D') y--;
		if(mp[x][y]>=2)
		{
			cout<<"BUG"<<endl;
			return 0;
		}
	}
	cout<<"OK"<<endl;
	return 0;
}
