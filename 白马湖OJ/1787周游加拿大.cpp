#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxm = 10010;
map < string, int > mp; 
void 
int main() {
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		mp[s] = i;
	}
	string x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		
	}
	return 0;
}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 105;
//int n,m,Len[N],f[N][N];
//bool Arrive[N][N];
//map < string , int > t;
//int main()
//{
//	string a,b,k;
//	scanf("%d%d",&n,&m);
//	for(int i = 1;i <= n;i ++)
//		cin >> k,t[k] = i,Arrive[i][i] = true;
//	for(int i = 1;i <= m;i ++)
//		cin >> a >> b,Arrive[t[a]][t[b]] = true,Arrive[t[b]][t[a]] = true;
//	f[1][1] = 1;
//	for(int i = 1;i <= n;i ++)
//		for(int j = i;j <= n;j ++)
//		{
//			for(int x = 1;x < i;x ++)
//			{
//				if(Arrive[i][x] && Arrive[j][x])
//				{
//					if((f[i][j] < f[x][i] + 1) && f[x][i])
//						f[i][j] = f[x][i] + 1;
//					if((f[i][j] < f[x][j] + 1) && f[x][j])
//						f[i][j] = f[x][j] + 1; 
//				}
//			}
//			for(int x = i;x < j;x ++)
//			{
//				if(x == i && i == j)	continue;
//				if(Arrive[i][x] && Arrive[j][x])
//				{
//					if((f[i][j] < f[i][x] + 1) && f[i][x])
//						f[i][j] = f[i][x] + 1;
//				}
//			}
//			printf("%d %d %d\n",i,j,f[i][j]);
//		}
//	printf("%d",f[n][n] + 1);
//	return 0;
//} 
