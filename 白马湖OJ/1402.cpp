#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n, m, k_top;
int a[10][10];
bool ans = false;

void f(int x, int y, int k)
{
	if (k > k_top) return;
	if (x == 0 || y == 0 || x == (m + 1) || y == (n + 1)) return;
	if (a[x][y] == 1) return;
	if (a[x][y] == 3) {ans = true; return;}
	printf("%d %d %d\n", x, y, k);
	f(x + 1, y, k + 1);
	f(x - 1, y, k + 1);
	f(x, y + 1, k + 1);
	f(x, y - 1, k + 1);
}

int main()
{
	char str[10], ch;
	int i, j;
	int st[3], ed[3];
	scanf("%d%d%d", &n, &m, &k_top);
	for (i = 1; i <= m; i++)
	{
		j = 1;
		while (j <= n)
		{
			j++;
			scanf("%c", &ch);
			printf("%c %d %d\n", ch, i, j);
			if (ch == 'S') {st[1] = i, st[2] = j; a[i][j] = 2;}
			else if (ch == 'D') {ed[1] = i, ed[2] = j; a[i][j] = 3;}
			else if (ch == 'X') {a[i][j] = 1;}
			else if (ch == '.') {a[i][j] = 0;}
			else j--;
		}
		puts("");
	}
	f(st[1], st[2], 0);
	if (ans == true) printf("YES\n");
	else printf("NO\n");
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d", a[i][j]);
		}
		puts("");
		
	}
	return 0;
}
