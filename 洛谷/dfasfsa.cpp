#include<iostream>
#include<cstring>
#include<cstdio>
#define re register
#define maxn 1005
#define eps 1e-6
#define M 51
double a[M][M],b[M][M];
double pi[M],dp[maxn][maxn];
int O[maxn];
int n,m,Q;
inline int check(double t,double k)
{
    if(t+eps>k&&t-eps<k) return 1;
    return 0;
}
int main()
{
	freopen("INPUT","r",stdin);
    scanf("%d%d%d",&n,&m,&Q);
    for(re int i=1;i<=n;i++)
        scanf("%lf",&pi[i]);
    for(re int i=1;i<=n;i++)
        for(re int j=0;j<Q;j++)
            scanf("%lf",&a[i][j]);
    for(re int i=1;i<=n;i++)
        for(re int j=1;j<=n;j++)
            scanf("%lf",&b[i][j]);
    for(re int i=1;i<=m;i++)
        scanf("%d",&O[i]);
    for(re int i=1;i<=n;i++)
        dp[1][i]=pi[i]*a[i][O[1]];
    for(re int i=1;i<m;i++)
        for(re int j=1;j<=n;j++)
        {
            if(check(dp[i][j],0)) continue;
            for(re int k=1;k<=n;k++)
                dp[i+1][k]+=dp[i][j]*a[k][O[i+1]]*b[j][k];
        }
    double ans=0;
    for (re int i=1;i<=m;i++)
	{
    	for (re int j=1;j<=n;j++)
    		ans+=dp[i][j];
		printf("> %.8lf\n",ans);
		ans=0;
	}
    for(re int i=1;i<=n;i++)
        ans+=dp[m][i];
    for(re int i=1;i<=n;i++)
    	printf("%.8lf\n",dp[m][i]);
    printf("%.8lf",ans);
    return 0;
}
