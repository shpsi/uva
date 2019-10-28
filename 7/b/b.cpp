#include <iostream>
 
using namespace std;
int a[105];
 
int main()
{
    int t,m,i,j;
    cin>>t>>m;
    int v=1;
    while(t--)
	{
		string s;
		cin>>s;
		int k;
		if(s=="alloc")
		{
	    	cin>>k;
	    	for(i=0;i<=m-k;i++)
			{
				for(j=i;j<i+k;j++)
					if(a[j]!=0)break;
				if(j==i+k)break;
	    	}
	    	if(i<=m-k)
			{
				cout<<v<<endl;
				for(j=i;j<i+k;j++) a[j]=v;
				v++;
	    	}
			else cout<<"NULL"<<endl;
		}
		else 
			if(s=="erase")
			{
	    		int f=0;
	    		cin>>k;
	    		for(i=0;i<m;i++)
					if(a[i]&&a[i]==k)
					{
						a[i]=0;
						f=1;
	    			}
	    		if(!f)puts("ILLEGAL_ERASE_ARGUMENT");
			}
			else
			{
	    		for(i=0,j=0;i<m;i++)
					if(a[i]) a[j++]=a[i];
	    		for(;j<m;j++)a[j]=0;
			}
    }
}
