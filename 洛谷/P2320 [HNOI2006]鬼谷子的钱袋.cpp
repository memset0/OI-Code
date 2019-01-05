// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int n;
vector < int > p; 

int main() {
	
	n = read();
	while (n) {
		p.push_back((n + 1) >> 1);
		n = n >> 1;
	}
	printf("%d\n", p.size());
	for (vector < int > ::reverse_iterator it = p.rbegin(); it != p.rend(); it++)
		printf("%d ", *it);
	puts("");
	
	return 0;
}