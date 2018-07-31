//非常牛逼的拓扑排序，100分
#include <bits/stdc++.h> 
using namespace std;
const int maxn = 5010;
const int maxm = 100010;
int n, m, x, y, len, waiting, cnt = 0, more, beat[maxn][maxn], visit[maxn], in_degree[maxn];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		beat[x][y] = 1;
		in_degree[y]++;
	}
	while (cnt < n) {
		len = 0;
		for (int i = 1; i <= n; i++) {
			if (!in_degree[i] && !visit[i]) {
				if (len == 0) waiting = i;
				len++;
			}
		}
		more |= len > 1;
		printf("%d\n", waiting);
		cnt++, visit[waiting] = 1;
		for (int j = 1; j <= n; j++) {
			if (beat[waiting][j]) {
				beat[waiting][j] = 0;
				in_degree[j]--;
			}
		}
	}
	cout << more;
	return 0;
}


//非常简单的sort排序，60分 
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 5010;
//const int maxm = 100010;
//int n, m, x, y, a[maxn][maxn], b[maxn];
//bool another = false;
//bool my_sort(int x, int y) {
//	if (!a[x][y] && !a[y][x]) {
//		another = true;
//		return x < y;
//	}
//	else return (a[x][y] > a[y][x]);
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		scanf("%d%d", &x, &y);
//		a[x][y] = 1;
//		for (int i = 1; i <= n; i++) { 
//			a[i][y] |= a[i][x]; //能打败x的球队一定能够打败y 
//			a[x][i] |= a[y][i]; //y打败了的球队一定能被y打败 
//		} 
//	}
//	for (int i = 1; i <= n; i++) b[i] = i;
//	sort(b + 1, b + n + 1, my_sort);
//	for (int i = 1; i <= n; i++) printf("%d\n", b[i]);
//	printf("%d\n", another);
//	return 0;
//}
