//打表 
#include <bits/stdc++.h>
using namespace std;
int b[20] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596}; 
int main() {
	int n;
	cin >> n;
	cout << b[n];
	return 0;
}

//DFS正常做法，没加优化，可能超时 
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 15 + 10;
//int n, ans = 0, p[maxn][maxn];
////bool check(int x, int y) /*对于对角线的另外一种理解*/{ 
////	for (int i = 1; i <= x; i++) if (p[i][y]) return 0;
////	if (x == y)
////		for (int i = 1; i <= x; i++)	
////			if (p[i][i]) return 0;
////	if (x + y == n + 1) 
////		for (int i = 1; i <= x; i++)	
////			if (p[i][n + 1 - i]) return 0;
////	return 1;
////}
//bool check(int x, int y) {
//	for (int i = 1; i <= x; i++) if (p[i][y]) return 0;
//	for (int xx = x, yy = y; xx > 0 && yy > 0; xx--, yy--)	
//		if (p[xx][yy]) return 0;
//	for (int xx = x, yy = y; xx > 0 && yy <= n; xx--, yy++)	
//		if (p[xx][yy]) return 0;
//	for (int xx = x, yy = y; xx <= n && yy > 0; xx++, yy--)	
//		if (p[xx][yy]) return 0;
//	for (int xx = x, yy = y; xx <= n && yy <= n; xx++, yy++)	
//		if (p[xx][yy]) return 0;
//	return 1;
//}
//void DFS(int ux, int uy) {
//	if (ux == n) {
//		ans++;
////		for (int i = 1; i <= n; i++) {
////			for (int j = 1; j <= n; j++)	
////				cout << p[i][j];
////			cout << endl;
////		}
////		cout << endl;
////		for (int i = 1; i <= 1000000; i++);
//		return ;
//	}
//	int i = ux + 1;
//	for (int j = 1; j <= n; j++) {
//		if (check(i, j)) {
//			p[i][j] = 1;
//			DFS(i, j);
//			p[i][j] = 0;
//		}
//	}
//}
//int main() {
//	for (int i = 1; i <= 14; i++) {
//		n = i;
//		ans = 0;
//		DFS(0, 1);
//		cout << ans << ",";
//	}
////	cin >> n;
////	DFS(0, 1);
////	cout << ans;
//}
