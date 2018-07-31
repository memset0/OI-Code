#include <bits/stdc++.h>
using namespace std;
int a[7][9], b[7][9];
int stp;
void cge_(int i, int j, int x, int y) {
	if (stp > 0) b[i][j] = a[x][y];
	else b[x][y] = a[i][j];
}
void cge(int a, int b) {
	int i = (a - 1) / 8 + 1;
	int j = (a - 1) % 8 + 1;
	int x = (b - 1) / 8 + 1;
	int y = (b - 1) % 8 + 1;
	cge_(i, j, x, y);
}
void cge_gap1(int k) {
	cge_(k, 1, k, 3);
	cge_(k, 2, k, 4);
	cge_(k, 3, k, 5);
	cge_(k, 4, k, 6);
	cge_(k, 5, k, 7);
	cge_(k, 6, k, 8);
	cge_(k, 7, k, 1);
	cge_(k, 8, k, 2);
}
void cge_gap2(int a, int b, int c, int d, int e, int f) {
	cge(a, d);
	cge(b, e);
	cge(c, f);
}
void cge_gap3(int a, int b, int c, 
	int d, int e, int f, 
	int g, int h, int i, 
	int j, int k, int l) {
	cge_gap2(a, b, c, d, e, f);
	cge_gap2(d, e, f, g, h, i);
	cge_gap2(g, h, i, j, k, l);
	cge_gap2(j, k, l, a, b, c);
}
void cge_gap4(int k) {
	switch (k) {
		case 1 : cge_gap3(17, 24, 23, 47, 46, 45, 31, 30, 29, 39, 38, 37); break;
		case 2 : cge_gap3(43, 42, 41, 21, 20, 19, 35, 34, 33, 27, 26, 25); break;
		case 3 : cge_gap3(47, 48, 41,  3,  4,  5, 35, 36, 37, 15, 16,  9); break;
		case 4 : cge_gap3(33, 40, 39,  1,  8,  7, 45, 44, 43, 13, 12, 11); break;
		case 5 : cge_gap3( 1,  2,  3, 27, 28, 29,  9, 10, 11, 17, 18, 19); break;
		case 6 : cge_gap3( 7,  6,  5, 23, 22, 21, 15, 14, 13, 25, 32, 31); break;
		
//		case 1 : cge_gap3(17, 24, 23, 47, 46, 45, 31, 30, 29, 39, 38, 37); break;
//		case 2 : cge_gap3(43, 42, 41, 27, 26, 25, 35, 34, 33, 21, 20, 19); break;
//		case 3 : cge_gap3(03, 04, 05, 35, 36, 37, 15, 16, 17, 47, 48, 41); break;
//		case 4 : cge_gap3(01, 08, 07, 45, 44, 43, 13, 20, 19, 33, 40, 39); break;
//		case 5 : cge_gap3(01, 02, 03, 27, 28, 29, 17, 18, 19,z); break;
	}
}
void write() {
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 8; j++)
			printf("%d ", a[i][j]);
		puts("");
	}
	puts("");
}
int main() {
	for (int i = 1; i <= 6; i++) 
		for (int j = 1; j <= 8; j++) 
			a[i][j] = (i - 1) * 8 + j;
//	write();
	scanf("%d", &stp);
	while (stp != 0) {
		for (int i = 1; i <= 6; i++)
			for (int j = 1; j <= 8; j++)	
				b[i][j] = a[i][j];
		cge_gap1(abs(stp));
		cge_gap4(abs(stp));
		for (int i = 1; i <= 6; i++)
			for (int j = 1; j <= 8; j++)	
				a[i][j] = b[i][j];
//		write();
		scanf("%d", &stp);
	}
	write();
}
