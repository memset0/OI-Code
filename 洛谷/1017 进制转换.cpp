#include <bits/stdc++.h>
using namespace std;
int n, k;
void write(int x) {
	printf("%d ", abs(x));
}
int main() {
	cin >> n >> k;
	while (n != 0) {
		write(n % k);
		n /= k;
	}
}
