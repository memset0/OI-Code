#include <bits/stdc++.h>
#define isNum(c) ('0'<=c&&c<='9')
#define isLetter(c) (('a'<=c&&c<='z')||('A'<=c&&c<='Z'))
using namespace std;
int n, k, l, r, ret, this_time, dis[1010];
bool isError;
char c, v;
int read() {
	char c = getchar();
	while (!(isNum(c) || c == 'n')) c = getchar();
	if (c == 'n') return -1;
	ret = 0;
	while (isNum(c)) {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret;
}
int read_o() {
	ret = read();
	if (ret == -1) return read();
	return ret();
}
char read_c() {
	c = getchar();
	while (!isLetter(c)) c = getchar();
	return c;
}
struct struct_var {
	char n[1010], l = 0;
	void push(char c) {
		n[++l] = c;
	}
	char pop() {
		return n[l--];
	}
	int count(char c) {
		for (int i = 1; i <= l; i++)
			if (n[i] == c) return 1;
		return 0;
	}
} var;
struct struct_time {
	int n[1010], l = 0;
	void push(int c) {
		n[++l] = c;
	}
	int pop() {
		return n[l--];
	}
	int count(int c) {
		for (int i = 1; i <= l; i++)
			if (n[i] == c) return 1;
		return 0;
	}
} time;
int main() {
	k = read();
	while (k--) {
		n = read(), ans = read_o();
		now = 0; top = 0;
		isError = false;
		memset(dis, 0, sizeof(dis));
		for (int i = 1; i <= n; i++) {
			a = read_c();
			if (a == 'F') {
				v = read_c(); l = read(); r = read();
				if (!isError) {
					if (var.count(v)) {
						isError = true;
						continue;
					}
					var.push(v);
//					if (x == -1 || y == -1) {
//						if (x == -1 && y == -1) todo = 1;
//						if (x == -1) todo = 0;
//						if (y == -1) todo = 2;
//					} else {
//						if (x <= y) todo = 1;
//						else todo = 0;
//					}
					if (x == -1 && y == -1) this_time = 1;
					else if (x == -1) this_time = 0;
					else if (y == -1) this_time = 2;
					else if (x <= y) this_time = 1;
					else this_time = 0;
					time.push(this_time);
				}
			} else if (a == 'E') {
				if (!isError) {
					dis[top--] = 0;
					var.pop();
				}
			}
		}
	}
	return 0;
}
