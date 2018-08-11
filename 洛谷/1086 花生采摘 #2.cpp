// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define y1 this_is_not_y1
#define y2 this_is_not_y2
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int n, m, Time, Map[21][21], ans = 0;

void dfs(int nowtime,int x,int y) {
	int Maxx,Maxy,Max = -99999;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (Map[i][j] > Max) {
				Max = Map[i][j];
				Maxx = i;
				Maxy = j;
			}
	if (!y) y = Maxy;
	if (nowtime < abs(x-Maxx)+abs(y-Maxy)+Maxx+1 || !Map[Maxx][Maxy])
		return;
	else {
		ans += Map[Maxx][Maxy];
		Map[Maxx][Maxy] = 0;
		dfs(nowtime-abs(x-Maxx)-abs(y-Maxy)-1,Maxx,Maxy);
	}
}
int main() {
	n = read(), m = read(), Time = read();
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			Map[i][j] = read();
	dfs(Time, 0, 0);
	printf("%d\n", ans);
	return 0;
}
