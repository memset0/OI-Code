// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define y1 this_is_not_y1
#define y2 this_is_not_y2
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
	
	int a = read(), b = read();
	printf("%d\n", [](int a, int b) {return a + b;}(a, b));
	
	return 0;
}

