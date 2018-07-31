#include <bits/stdc++.h>
using namespace std;
int main() {
	long long s = 0;
	int n, a;
	scanf("%d", &a);
	while (a != -1) {
		n++, s += a;
		scanf("%d", &a);
	}
	cout << s;
	return 0;
}
