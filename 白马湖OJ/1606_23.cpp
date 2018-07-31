		#include <bits/stdc++.h>
		using namespace std;
		bool my_sort(int a, int b) {return a > b;}
		int f[1500];
		int main()
		{
			int a[5][30];
			for (int i = 1; i <= 4; i++)
				scanf("%d", &a[i][0]);
			for (int i = 1; i <= 4; i++)
				for (int j = 1; j <= a[i][0]; j++)
					scanf("%d", &a[i][j]);
			int ans = 0, sum;
			for (int flag = 1; flag <= 4; flag++)
			{
				memset(f, 0, sizeof(f));
				sum = 0;
				f[0] = 1;
				for (int i = 1; i <= a[flag][0]; i++)
				{
					sum += a[flag][i];
					for (int j = sum; j >= a[flag][i]; j--)
						f[j] |= f[j - a[flag][i]];
				}
				for (int i = sum/2; i >= 0; i--)
					if (f[i])
					{
						ans += max(i, sum-i);
						break;
					}
			}
			printf("%d", ans);
			return 0;
		}
