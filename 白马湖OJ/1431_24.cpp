#include<cstdio>
#include<cstring>
char a[110][110];
bool b[110][110];
int t,n,m;
void dfs(int x, int y, int s)
{
	if ((x < 0) || (x >= n) || (y < 0) || (y >= m))
		return ;
	if ((used[x][y]>0)||(a[x][y]!='#'))
		return ;
	used[x][y]=1;
	dfs(x-1,y,s);
	dfs(x,y-1,s);
	dfs(x,y+1,s);
	dfs(x+1,y,s);
	return ;
}
int main()
{
	scanf("%d",&t);
	for (int k=1;k<=t;++k)
	{
		int ans=0;
		memset(used,0,sizeof(used));
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;++i)
			scanf("%s",a[i]);
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
				if ((used[i][j]==0)&&(a[i][j]=='#'))
					dfs(i,j,++ans);
		printf("%d\n",ans);
	}
	return 0;
}
