#include <bits/stdc++.h> 
using namespace std;
int n, m, i, j, k, l = 0, a[62510], b[1251000], top = 125000;
struct Node {
	int a, b; 
} s[10010];
int stop = 0;
bool cmp(Node a, Node b) {
	if (a.b == b.b) return a.a < b.a;
	return a.b < b.b;
}
int main() {
	scanf("%d%d", &n, &m);
	for (i = 0; i <= m; i++)
		for (int j = i; j <= m; j++) {
//			printf("%d\n", i * i + j * j);
			b[i * i + j * j] ++;
		}
	for (i = 0; i <= top; i++)
		if (b[i])
			a[++l] = i;
	int aa, bb;
	bool flag;
	for (i = 1; i <= l; i ++) {
		for (j = i + 1; j <= l; j ++) {
			bb = a[j] - a[i];
			aa = a[i] - bb;
			flag = true;
			for (k = 3; k <= n; k++)
				if (!b[aa + k * bb]) {
					flag = false;
					break;
				}
			if (flag) {
				s[++stop] = {
					a[i], bb
				};
			}
		}
	}
	sort(s + 1, s + stop + 1, cmp);
	for (int i = 1; i <= stop; i++)
		printf("%d %d\n", s[i].a, s[i].b);
	if (!stop) printf("NONE\n");
	return 0;
}	

