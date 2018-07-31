#include <bits/stdc++.h>
using namespace std;
int read(void);
char readchar(void);
void printq(void);

const int maxn = 20;
int n;
char a[maxn][maxn];

const int mov[4][4] = {
	{-1, 0, 1, 0}, {-1, 0, 0, 1}, 
	{0, -1, 1, 0}, {0, -1, 0, 1}};
int i, j, l = 1, r = 0, ans = 0;
string col;

struct Tree {
	set < string > s;
	string tmp;
	bool find(string &c) {
		return s.count(c);
	}
	bool add(string &c) {
		s.insert(c);
	}
} s;

void DFS(int i, int j, int k) {
	if (i < 1 || j < 1 || i > n || j > n) return ;
	if (k <= n) col[k] = a[i][j];
	else {
		if (s.find(col) || a[i][j] != col[n * 2 - k]) return ;
		if (i == n && j == n) {
			ans++;
			s.add(col);
			return ;
		}
	}
	DFS(i + 1, j, k + 1);
	DFS(i, j + 1, k + 1);
}
int main() {
//	freopen("palpath.in", "r", stdin);
//	freopen("palpath.out", "w", stdout);
	
	col = "                    ";
	n = read();
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			a[i][j] = readchar();
	
	DFS(1, 1, 1);
//	s.print_tree();
	printf("%d\n", ans);
	
	return 0;
}

int ret; char chr; bool mrk;
int read() {
	chr = getchar(), ret = mrk = 0;
	while (!('0' <= chr && chr <= '9') && chr != '-') chr = getchar();
	if (chr == '-') mrk = 1, chr = getchar();
	while ('0' <= chr && chr <= '9') ret = ret * 10 + chr - '0', chr = getchar();
	if (mrk) return -ret; else return ret;
}
char readchar() {
	chr = getchar();
	while (!('A' <= chr && chr <= 'Z')) chr = getchar();
	return chr;
}

/*
4
ABCD
BXZX
CDXB
WCBA
*/

// 下面那个版本是把重复的分开来算的 
// 我真是个**啊 

//#include <bits/stdc++.h>
//using namespace std;
//int read(void);
//char readchar(void);
//void printq(void);
//
//const int maxn = 20;
//int n;
//char a[maxn][maxn];
//
//const int mov[4][4] {
//	{-1, 0, 1, 0}, {-1, 0, 0, 1}, 
//	{0, -1, 1, 0}, {0, -1, 0, 1}
//};
//int i, j, l = 1, r = 0, ans = 0;
//struct Queue {
//	int ai, aj, bi, bj;
//} q[10000000], u, v;
//
//// 绑定的BFS 
//int main() {
//	freopen("palpath.in", "r", stdin);
////	freopen("palpath.out", "w", stdout);
//	
//	n = read();
//	for (i = 1; i <= n; i++)
//		for (j = 1; j <= n; j++)
//			a[i][j] = readchar();
//	
//	for (i = 1; i <= n; i++)
//		q[++r] = {i, n + 1 - i, i, n + 1 - i};
//	
//	while (l <= r) {
//		u = q[l++];
//		printf("%d %d %d %d\n", u.ai, u.aj, u.bi, u.bj);
//		for (i = 0; i < 4; i++) {
//			v.ai = u.ai + mov[i][0];
//			v.aj = u.aj + mov[i][1];
//			v.bi = u.bi + mov[i][2];
//			v.bj = u.bj + mov[i][3];
//			if (v.ai < 1 || v.aj < 1 || v.bi > n || v.bj > n) continue;
//			if (v.ai == 1 && v.aj == 1 && v.bi == n && v.bj == n) {
//				//费劲千辛万苦总算找到了一个答案 
//				ans++;
//			} else if (a[v.ai][v.aj] == a[v.bi][v.bj]) {
//				//还没到终点，继续加油 
//				q[++r] = v;
//			}
//		}
//	}
//	printf("%d\n", ans);
//	
//	return 0;
//}
//
//int ret; char chr; bool mrk;
//int read() {
//	chr = getchar(), ret = mrk = 0;
//	while (!('0' <= chr && chr <= '9') && chr != '-') chr = getchar();
//	if (chr == '-') mrk = 1, chr = getchar();
//	while ('0' <= chr && chr <= '9') ret = ret * 10 + chr - '0', chr = getchar();
//	if (mrk) return -ret; else return ret;
//}
//char readchar() {
//	chr = getchar();
//	while (!('A' <= chr && chr <= 'Z')) chr = getchar();
//	return chr;
//}
//void printq(){
//	for (int i = l; i <= r; i++)
//		printf("%d %d %d %d\n", q[i].ai, q[i].aj, q[i].bi, q[i].bj);
//} 
