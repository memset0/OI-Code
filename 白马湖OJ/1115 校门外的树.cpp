#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxm = 10010;
int n, m, a, b, cnt = 0, r[maxm];
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i <= m; i++)
		r[i] = 1;
	for (int i = 1; i <= n; i++ ) {	
		scanf("%d%d", &a, &b);
		for (int i = a; i <= b; i++)	
			r[i] = 0;
	} 
	for (int i = 0; i <= m; i++) {
		cnt += r[i];
	}
	cout << cnt << endl;
	return 0;
}
