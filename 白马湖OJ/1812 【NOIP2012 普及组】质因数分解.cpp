#include <bits/stdc++.h>
using namespace std;
int n, m;
bool is_prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	cin >> n;
	for (int i = n; i >= 2; i--) {
		if (n % i == 0) {
			if (is_prime(i)) {
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}
