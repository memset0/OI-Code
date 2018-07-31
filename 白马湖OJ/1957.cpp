#include <bits/stdc++.h>
using namespace std;
int x, y, n, k, mov[5][2] = {
	{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}
};
int main() {
	scanf("%d%d%d", &x, &y, &n);
	while (n--) {
		scanf("%d", &k);
		x += mov[k][0];
		y += mov[k][1];
	}
	printf("%d %d\n", x, y);
	return 0;
}
