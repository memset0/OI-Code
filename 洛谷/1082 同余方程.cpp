// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.05 20:11:12
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

int a, b, t, ans;

struct solution {
	int x, y;
	solution(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
};

solution exgcd(int a, int b) {
	if (b == 0) return solution(1, 0);
	solution ret = exgcd(b, a % b);
	// printf("%d %d => %d %d\n", a, b, ret.y, ret.x - (a / b) * ret.y);
	return solution(ret.y, ret.x - (a / b) * ret.y);
}

int main() {
	a = read(), b = read();
	printf("%d\n", (exgcd(a, b).x % b + b) % b);
	return 0;
}