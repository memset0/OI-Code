#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,z;
int f[2][205][205];

void rd()
{
	scanf("%d%d%d%d%d",&x,&y,&z,&n,&m);
	m ++;
}

int main()
{
	
	rd();
	f[1][0][0] = 1;
	f[1][1][1] = 1;
	for(int i = 2; i <= m; i ++)
		f[0][1][i] = 1;
	for(int i = 1; i <= m; i ++)
		f[0][0][i] = 1;
	
	for(int i = 2; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			for(int k = 0; k <= i-1; k ++)
				f[0][i][j] = (f[0][i][j] + f[0][k][j-1] * f[0][i-k-1][j-1])%2016; 
			if(j > i) continue;
			for(int k = 0; k <= i-1; k ++)
			{ 
				f[1][i][j] = (f[1][i][j] + f[1][k][j-1]*f[0][i-k-1][j-1]%2016 + f[0][k][j-1]*f[1][i-k-1][j-1]%2016 + f[1][k][j-1]*f[1][i-k-1][j-1]%2016)%2016;  
			} 
		//	cout<<i<<" "<<j<<" "<<f[0][i][j]<<" "<<f[1][i][j]<<"\n";
		}	
	}
	cout<<f[1][n][m]%2016;
	return 0;
} 
