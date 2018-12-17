// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#include <windows.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int main() {
	srand(GetTickCount());
	freopen("3.txt", "w", stdout);
	
	int n = 5, m = 5;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= m; i++) {
		int opt = rand() % 3 + 1;
		if (opt == 1)  {
			printf("1 %d %d\n", rand() % n + 1, rand() % n + 1);
		} else if (opt == 2 && i != 1) {
			printf("2 %d\n", rand() % (i - 1) + 1); 
		} else {
			printf("3 %d %d\n", rand() % n + 1, rand() % n + 1);
		}
	}

	return 0;
}

