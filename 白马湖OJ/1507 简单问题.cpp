#include <bits/stdc++.h>
#define R 10000
#define R_ 4
#define CLE 'c' 
using namespace std;
const int maxn = 300;
int n;
struct num {
	int len, n[maxn];
	int& operator [] (int k) {
		//闲着无聊打个重载运算符 
		return n[k];
	}
	int& operator () (char c) {
		if (c == 'c')  {
			memset(n, 0, sizeof(n));
			len = 0;
		}
	}
} b, m, l, r, mid;

void write(num a) {
	printf("%d", a[a.len]);
	for (int i = a.len - 1; i > 0; i--)
		printf("%04d", a[i]);
	puts("");
	return ;
}

num read() {
	char s[1500]; gets(s); int sl = strlen(s);
	num t; t(CLE); t.len = (sl + R_ - 1) / R_;
//	cout << t.len << endl;
	for (int i = 1; i <= t.len; i++) {
		t[i] = 0;
		for (int j = min(i * R_, sl); j >= i * R_ - R_ + 1 && j >= 0; j--)
			t[i] = t[i] * 10 + s[sl - j] - '0';
	}
	return t;
}

num mul(num a) {
	num b; b(CLE);
	b.len = a.len + a.len;
	for (int i = 1; i <= a.len; i++)
		for (int j = 1; j <= a.len; j++) {
			b[i + j - 1] += a[i] * a[j];
			b[i + j] += b[i + j - 1] / R;
			b[i + j - 1] %= R;
		}
	while (!b[b.len] && b.len) b.len--;
	return b;
}

num get_mid(num l, num r) {
	num a; a(CLE);
	a.len = max(l.len, r.len) + 1;
	for (int i = 1; i <= a.len; i++) {
		a[i] += l[i] + r[i];
		a[i + 1] += a[i] / R;
		a[i] %= R;
	}
	while (!a[a.len] && a.len) a.len--;
//	write(a);
	for (int i = a.len; i > 0; i--) {
		a[i - 1] += (a[i] % 2) * R;
		a[i] /= 2;
	}
//	write(a);
	while (!a[a.len] && a.len) a.len--;
	return a;
}

num lowplus(num a, int b) {
	a[1] += b;
	for (int i = 1; (a[i] < 0 || a[i] >= R) && i < a.len; i++) {
		while (a[i] < 0) a[i] += R;
		while (a[i] > R) {
			a[i + 1] += 1;
			a[i] -= R;
		}
	}
	return a;
}

bool cmp(num &a, num &b) {
	if (a.len != b.len) return a.len < b.len;
	for (int i = 1; i <= a.len; i++)
		if (a[i] != b[i]) return a[i] < b[i];
	return true;
}

num a;

//int main() {
//	a.len = 1;
//	for (int i = 1; i <= 50; i++) {
//		a[1] = i;
//		cout << i << " ";
//		a = mul(a);
//		write(a);
//	}
//	return 0;
//}

int main() {
	l[1] = l.len = 1;
	r = m = read();
	
	while (cmp(l, r)) {
		mid = get_mid(l, r);
		b = mul(mid);
//		write(l);
//		write(mid);
//		write(r);
//		cout << endl;
		if (cmp(b, m)) l = lowplus(mid, 1);
		else r = lowplus(mid, -1);
	}
	
	l = lowplus(l, -5);
	r = lowplus(r, 5);
//	write(l);
//	write(r);
	
	for (num i = r; cmp(l, i); i = lowplus(i, -1)) {
//		write(i);
		b = mul(i);
		if (cmp(b, m)) {
			write(i);
			return 0;
		}
	}
	return 0;
}
