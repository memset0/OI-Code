//区间动归 100分代码
#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
const int maxm = 110;
int n, m, a[maxm];
int f[maxm][maxm]; //f[i][j]表示a[i]到a[j]中间的房间至少要花费的费用 
int main()
{
	memset(f, 127, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)	
		scanf("%d", &a[i]);
	a[0] = 0, a[m + 1] = n + 1;
	for (int i = 0; i <= m; i++)
	{
		f[i][i] = 0;
		f[i][i + 1] = 0;
		for (int j = i+2; j <= m; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				int x = f[i][k] + f[k][j] + a[j] - a[i] - 2;
				if (x < f[i][j]) f[i][j] = x;
			}
		}
	}
	return 0;
}

//深搜 70分代码  
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 210;
//const int maxm = 110;
//int n, m, ans = 2147483647, a[maxm], fix[maxn], got[maxm];
//void DFS(int i, int u) { //i表示当前搜索第i个，已完成i-1个
//	if (u > ans) return ;
//	if (i > m) {
//		if (u < ans) ans = u;
//		return ;
//	}
//	for (int j = m; j >= 1; j--)
//		if (!got[j]) {
//			int v = u;
//			for (int k = a[j] + 1; !fix[k]; k++) v++;
//			for (int k = a[j] - 1; !fix[k]; k--) v++;
//			got[j] = 1;
//			fix[a[j]] = 1;
//			DFS(i + 1, v);
//			got[j] = 0;
//			fix[a[j]] = 0;
//		}
//}
//int main () {
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= m; i++)
//		scanf("%d", &a[i]);
//	fix[0] = 1;
//	fix[n+1] = 1;
//	DFS(1, 0);
//	cout << ans;
//	return 0;
//}
