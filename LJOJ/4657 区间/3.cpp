#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int n, k, p, A, B, C, D;

int r() {
	return ((rand()<<16)+(rand()<<1)+(rand()&1)) % 10;
}

int main() {
	srand(GetTickCount());
	
	n = r() % 200000 + 1;	
	k = r() % (n - 1) + 2;
	p = r();
	A = r();
	B = r();
	C = r();
	D = r();
	printf("%d %d %d\n%d %d %d %d\n", n, k, p, A, B, C, D);
	return 0;
}
