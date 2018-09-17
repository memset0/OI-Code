#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int edgenum,u[200005],v[200005],a[200005],b[200005],flag[200005],n,m,top,st[200005];
bool cmp(int t1,int t2)
{
	return t1>t2;
}
void addedge(int x,int y)
{
	edgenum++;
	u[edgenum]=x;
	v[edgenum]=y;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if (a[i]>b[i]) swap(a[i],b[i]);
	}
	for (int i=1;i<n;i++)
		if (b[i]!=n)
		{
			printf("NO\n");
			return 0;
		}
	for (int i=1;i<n;i++)
		flag[a[i]]=true;
	for (int i=1;i<n;i++)
		if (flag[i]==false) top++,st[top]=i;
	sort(a+1,a+n,cmp);
	m=n;
	for (int i=2,last=1;i<=n;i++)
		if (a[i]!=a[i-1])
		{
			int j=i-last-1;
			if (top<j)
			{
				printf("NO\n");
				return 0;
			}
			for (int k=1;k<=j;k++)
			{
				if (st[top]>a[i-1])
				{
					printf("NO\n");
					return 0;
				}
				addedge(m,st[top]),m=st[top],top--;
			}
			addedge(m,a[i-1]),m=a[i-1];
			last=i;
		}
	printf("YES\n");
	for (int i=1;i<=edgenum;i++)
		printf("%d %d\n",u[i],v[i]);
	return 0;
}

