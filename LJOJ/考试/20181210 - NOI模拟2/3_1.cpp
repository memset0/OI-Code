#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int mod=998244353;
int n,len,a[200005],b[200005],c[200005];
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		int x;
		scanf("%d%d",&n,&x);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		if (x==1) a[2]=1;
		else a[0]=x-2,a[1]=2;
		for (int i=2;i<=n;i++)
		{
			scanf("%d",&x);
			b[0]=b[1]=b[2]=0;
			if (x==1) b[2]=1;
			else b[0]=x-2,b[1]=2;

			for (int j=0;j<=i+i;j++)
				c[j]=0;
			for (int j=0;j<=i+i-2;j++)
				for (int k=0;k<=2;k++)
					c[j+k]=(c[j+k]+(long long)a[j]*b[k]%mod)%mod;
			for (int j=0;j<=i+i;j++)
				a[j]=c[j];
		}
		for (int i=0;i<=n+n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}