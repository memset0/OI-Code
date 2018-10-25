#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1 - i; j++)
			printf("%4d", ++cnt);
		puts("");
	}
	return 0;
}
