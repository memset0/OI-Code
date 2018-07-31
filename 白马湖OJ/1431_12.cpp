#include <bits/stdc++.h>
#define map lalala001
#define move lalala002
using namespace std;
int n, m, ans, _N_;
bool map[110][110];
char str[110];
int main()
{
	scanf("%d", &_N_);
	for (int _I_ = 1; _I_ <= _N_; _I_++)
	{
		ans = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str+1);
			for (int j = 1; j <= m; j++)
			{ 
				map[i][j] = (bool)(str[j] == '#');
				if (map[i][j] && !map[i-1][j] && !map[i][j-1]) 
					ans++;
			} 
		}
		printf("%d\n", ans);
	}
	return 0;
}
