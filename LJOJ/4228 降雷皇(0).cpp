#include <bits/stdc++.h>
using namespace std;

void read(int &p) {
	char c = getchar(); bool m = 0; p = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) p = p * 10 + c - '0', c = getchar();
	if (m) p = -p;
}

#define M 123456789
typedef long long ll;
 

const int maxn = 100010;
int n, type, a[maxn];

namespace solution1 {
	int ans = 0, f[maxn], sum = 0, cnt[maxn], g[maxn];
	void main() {
		memset(f, 0, sizeof(f));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			f[i] = cnt[i] = 1; 
			for (int j = 1; j < i; j++) {
				if (a[i] > a[j] && f[j] + 1 >= f[i]) {
					if (f[j] + 1 == f[i]) cnt[i] = (cnt[i] + cnt[j]) % M;
					else f[i] = f[j] + 1, cnt[i] = cnt[j];
				}
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				if (f[i] == f[j])
					g[i] += cnt[j];
//		for (int i = 1; i <= n; i++)
//			cout << f[i] << " ";
//		cout << endl;
//		for (int i = 1; i <= n; i++)
//			cout << g[i] << " ";
//		cout << endl;
		for (int i = 2; i <= n; i++)
			if (f[i] < f[i - 1]) f[i] = f[i - 1], g[i] = g[i - 1];
			else if (f[i] == f[i - 1] && g[i] < g[i - 1]) g[i] = g[i - 1];
		for (int i = 1; i <= n; i++)
			cout << f[i] << " ";
		cout << endl;
		for (int i = 1; i <= n; i++)
			cout << g[i] << " ";
		cout << endl;
		
		for (int i = 1; i <= n; i++)
			if (f[i] > ans)
				ans = f[i];
		for (int i = 1; i <= n; i++)
			if (f[i] == ans)
				sum = (cnt[i] + sum) % M;
		printf("%d\n", ans);
		if (type) printf("%d\n", sum);
	}
}

int main() {
	freopen("INPUT", "r", stdin);

	read(n), read(type);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	
	solution1::main();
//	if (type && n <= 1000) solution1::main();
//	else if (!type) solution2::main();
//	else solution3::main();
			
	return 0;
} 
