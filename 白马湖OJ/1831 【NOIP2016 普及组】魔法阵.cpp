#include <bits/stdc++.h>
using namespace std;

const int maxn = 15010;
const int maxm = 40010;
int n, m, t, a[maxm], b[maxn];
struct str_cnt{
	int a, b, c, d;
} cnt[maxm];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
		b[a[i]]++;
	}
	int D;
	for (int A = 1; A < n; A++) 
		if (b[A]){
			for (int B = A + 1; B < n; B++) 
				if (b[B]){
					for (int C = max(4 * B - 3 * A, B) + 1; C < n; C++) 
						if (b[C]){
							D = 2 * C + B - A;
							if (D % 2 != 0 || D <= C) continue;
							D = D / 2;
							if (b[D]) {
								// cout << A << " " << B << " " << C << " " << D << endl;
								cnt[A].a += b[B] * b[C] * b[D];
								cnt[B].b += b[A] * b[C] * b[D];
								cnt[C].c += b[A] * b[B] * b[D];
								cnt[D].d += b[A] * b[B] * b[C];
							}
						}
				}
	 	}
	for (int i = 1; i <= m; i++) {
		printf("%d %d %d %d\n", cnt[a[i]].a, cnt[a[i]].b, cnt[a[i]].c, cnt[a[i]].d);
	}
	return 0;
}
