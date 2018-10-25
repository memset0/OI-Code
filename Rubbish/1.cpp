#include <bits/stdc++.h>
using namespace std;
const int n = 100000000;
int tot = 0;
int flag[n + 1], prime[n + 1];
int main() {
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			prime[++tot] = i;
		}
		for (int j = 1; i * prime[j] <= n; j++) {
			flag[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	cout << tot << endl;
	return 0;
}
