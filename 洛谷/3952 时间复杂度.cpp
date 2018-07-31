#include <bits/stdc++.h> 
#define isNum(c) ('0'<=c&&c<='9')
using namespace std;
struct Read {
	int ret;
	char c;
	int i() {
		c = getchar();
		while (!isNum(c)) c = getchar();
		ret = 0;
		while (isNum(c)) {
			ret = ret * 10 + c - '0';
			c = getchar();
		}
		return ret;
	}
	int ch() {
		c = getchar();
		while (c == ' ' || c == '\n') c = getchar();
		return c;
	}
	int v() {
		c = getchar();
		while (!(isNum(c) || c == 'n')) c = getchar();
		if (c == 'n') return -1;
		else {
			ret = 0;
			while (isNum(c)) {
				ret = ret * 10 + c - '0';
				c = getchar();
			}
			return ret;
		}
	}
	int o() {
		c = getchar();
		while (!(c == '1' || c == 'n')) c = getchar();
		if (c == '1') ret = 0;
		else {
			while (!isNum(c)) c = getchar();
			ret = 0;
			while (isNum(c)) {
				ret = ret * 10 + c - '0';
				c = getchar();
			}
		}
		while (c != '\n') c = getchar();
		return ret;
	}
} read;
struct Stack {
	int len, a[110];
	void clean() {
		len = 0;
		memset(a, 0, sizeof(a));
	}
	void push(int x) {
		a[++len] = x;
	}
	void pop() {
		len--;
	}
	int front() {
		return a[len];
	}
} o, v;
int t, l, w, x, y, ans, cnt, ret;
bool vdis[256];
char vname, op, s[20];
int getO() {
	cnt = 0;
	for (int i = 1; i <= o.len; i++)
		if (o.a[i]) {
			if (o.a[i] == 2) cnt ++;
		} else return cnt;
	return cnt;
}
int check() {
	// YES => 1; NO => 0; ERR => -1;
	l = read.i(), w = read.o();
	o.clean(), v.clean();
	memset(vdis, 0, sizeof(vdis));
	ans = -1;
	while (l--) {
		op = read.ch();
		if (op == 'F') {
			// F 
			vname = read.ch();
			x = read.v(), y = read.v();
			if (vdis[vname]) return -1; //重复变量名
			v.push(vname), vdis[vname] = 1; //变量名入栈 
			if (x == -1 && y == -1) {
				// n -> n 常数复杂度 
				o.push(1);
			} else if (x == -1) {
				// n -> 1 不可进入 
				o.push(0);
			} else if (y == -1) {
				// 1 -> n n的复杂度 
				o.push(2);
			} else if (x > y) { 
				// 2 -> 1 不可进入
				o.push(0);
			} else {
				// 1 -> 2 常数复杂度 
				o.push(1);
			}
			ans = max(ans, getO());
		} else {
			// E
			if (v.len == 0) return -1; // E多余F => ERR
			vdis[v.front()] = 0, v.pop(); //变量名出栈 
			o.pop();
		}
	}
	if (v.len > 0) return -1; // F多余E => ERR 
	if (w == ans) return 1; // => YES
	else return 0; // => NO
}
int main() {
	t = read.i();
	while (t--) { 
		ret = check();
		if (l > 0) while (l--) if (read.ch() == 'F') {
			read.ch(); read.v(), read.v();
		} //过滤掉没有处理的输入
		if (ret == 1) puts("Yes");
		else if (ret == 0) puts("No");
		else puts("ERR");
	}
	
	return 0;
}
