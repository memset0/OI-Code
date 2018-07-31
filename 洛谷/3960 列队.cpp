#include <bits/stdc++.h> 
using namespace std;
const int maxn = 1010;
const int maxq = 510;
int n, m, q;
int a[maxn][maxn];
char Red; int Ret;
struct Q {
	int x, int y;
} b[maxq];
void read() {
	Red = getcahr();
	while (!isNum(Red)) Red = getchar();
	Ret = 0;
	while (isNum(Red)) {
		Ret = Ret * 10 + Red - '0';
		Red = getchar();
	}
	return Ret;
}
int main() {
	n = read(); m = read(); q = read();
	for (int i = 1; i <= q; i++) 
		b[i].x = read(), b[i].y = read();
	
	for (int i = 1; i <= q; i++) {
		x = b[i].x, y = b[i].y;
		
	}
	return 0;
}
