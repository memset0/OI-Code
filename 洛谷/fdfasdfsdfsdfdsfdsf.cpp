#include<iostream>
using namespace std;
#define maxn 200
#define maxr 200
int main()
{	int i,k,m,n,p,r,a[maxr];
	cin>>n>>r;
	for(i=1;i<=r;i++)  a[i]=i;
	for(i=1;i<=r;i++) cout<<a[i]<<" ";;
	cout<<endl;
	p=0;
	while(p<r)
	{
		m=r-1;
		k=n-p;
		if(a[m]<k)
		{	
a[m]=a[m]+1;
			for(i=m=1;i<=r;i++)	  a[i]=a[i-1]+1;
			for(i=1;i<=r;i++)  cout<<a[i]<<" ";
			p=0; 
			cout<<endl;		
		}
		else
		  p=p+1;		
	}
	return 0;
}

