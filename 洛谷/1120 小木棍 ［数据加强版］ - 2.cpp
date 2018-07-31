#include <bits/stdc++.h>
using namespace std;
const int maxn = 70;
const int maxm = 70 * 50;
int n, sum, lim, a[maxn];

void DFS(int u) {
	
}

int main() {
	freopen("INPUT", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > 50) i--, n--;
		else sum += a[i];
	}
	for (int i = 1; i <= sum; i++)
		if (sum % i == 0) {
			limit = i;
			DFS(1);
			if (found) {
				printf("%d\n", i);
				return 0;
			}
		}
	return 0;
} 
