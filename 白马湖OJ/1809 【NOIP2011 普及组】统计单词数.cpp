#include <bits/stdc++.h>
#define is_letter(c) ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z')
using namespace std;
const int maxn = 110;
const int maxm = 1000010;
struct Struct {
	char c[maxn];
	int len;
}u, v;
int len = 0, cnt = 0; 
int read(Struct &a) {
	char c;
	c = getchar();
	while (!is_letter(c) && c != EOF) {
		c = getchar();
	}
	while (c != ' ' && c != EOF) {
		if (is_letter(c)) {
//		cout << c;
			if (c > 'z') a.c[a.len++] = c - 'A' + 'a';
			else a.c[a.len++] = c;
		}
		c = getchar();
	}
	if (c == EOF) return EOF;
	else return 0;
}
void write(Struct a) {
	for (int i = 1; i <= a.len; i++)
		putchar(a.c[i]);
}
bool check(Struct a, Struct b) {
	if (a.len != b.len) return false;
	for (int i = 1; i <= a.len; i++) {
		if (a.c[i] != b.c[i])
			return false;
	}
	return true;
}
int main() {
	read(u);
	while (read(v) != EOF) {
		if (check(u, v)) cnt++;
		cout << v.len;
		v.len = 0;
	}
	cout << cnt;
	return 0;
}
