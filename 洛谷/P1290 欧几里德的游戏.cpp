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

int n, m, T, flag;
double A, B;

int main() {

	T = read();
	while (T--) {
		n = read(), m = read();
		if (n == m) printf("Stan wins\n");
		else {
			if (n < m) swap(n, m), flag = 1;
			else flag = 0;
			A = n * 1.0 / m;
			B = (sqrt(5) + 1) / 2;
//			cout << A << " " << B << " " << (A > B) << endl;;
			if ((A > B)) 
				printf("Stan wins\n");
			else
				printf("Ollie wins\n");
		}
	}
	
	return 0;
}
