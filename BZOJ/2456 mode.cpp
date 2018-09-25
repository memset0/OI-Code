// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <stdio.h>

int n, x, i, now, cnt = 1;

int main() {

	scanf("%d%d", &n, &now);
	for (i = 2; i <= n; i++) {
//		printf("%d %d\n", now, cnt);
		scanf("%d", &x);
		cnt += x == now ? 1 : -1;
		if (!cnt) now = x, cnt = 1;
	}
	printf("%d\n", now);
	
	return 0;
}
