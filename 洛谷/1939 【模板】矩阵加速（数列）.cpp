#include <bits/stdc++.h>
using namespace std;
struct matrix {
	int a[3][3];
	void clean() {
		memset(a, 0, sizeof(a));
	}
	void mul(matrix x, matrix y) {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					a[i][j] += x.a[i][k] * y.a[k][j];
	}
};
int t, n; 
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("")
	}
	return 0;
}
