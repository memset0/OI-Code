#include <bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar(); bool m = 0; int x = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) x = -x;
	return x;
}
const int maxn = 50010;
const int sqrn = 250;
int n, a[maxn];
class Square {
	public:
		void build(void) {
			memset(tag, 0, sizeof(tag));
			sqn = sqrt(n);
			for (int i = 1; i <= n; i++) {
				val[i] = a[i];
				bln[i] = (i - 1) / sqn + 1;
			}
		}
		void update(int l, int r, int c) {
			if (l > r) return;
			if (bln[l] == bln[r]) {
//				cout << "!!!!!";	 
				for (int i = l; i <= r; i++)
					val[i] += c;
			} else {
				for (int i = l; i <= bln[l] * sqn; i++)
					val[i] += c;
				for (int i = bln[r - 1] * sqn + 1; i <= r; i++)
					val[i] += c;
				for (int i = bln[l] + 1; i <= bln[r] - 1; i++)
					tag[i] += c; 
			}
		}
		int query(int x) {
			return (val[x] + tag[bln[x]]);
		}
		void print() {
			cout << "=== Square[" << print_cnt++ << "] ===" << endl;
			cout << "val[] = ";
			for (int i = 1; i <= n; i++)
				cout << val[i] << " ";
			cout << endl;
			cout << "bln[] = ";
			for (int i = 1; i <= n; i++)
				cout << bln[i] << " ";
			cout << endl;
			cout << "tag[] = ";
			for (int i = 1; i <= sqn + 1; i++)
				cout << tag[i] << " ";
			cout << endl;
		}
	private:
		int sqn, val[maxn], bln[maxn], tag[sqrn];
		int print_cnt = 0;
}; 
int main() {
//	freopen("TESTDATA1.in", "r", stdin);
	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	n = read();
//	cout << n <<endl;
	for (int i = 1; i <= n; i++)
		a[i] = read();
	Square square;
	square.build();
	for (int i = 1; i <= n; i++) {
		int opt, l, r, c;
		opt = read(), l = read(), r = read(), c = read();
		printf(">>> %d %d %d %d\n", opt, l, r, c);
		if (opt == 0) {
			square.update(l, r, c);
		} else if (opt == 1) {
			printf("%d\n", square.query(r));
		}
		square.print();
	}
	return 0;
}
