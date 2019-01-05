#include <bits/stdc++.h>
int n, a[110];
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		for (int j = 1; j < i; j++)
			if (a[i] > a[j]) a[i + 1]++;
		std::cout << a[i + 1] << " ";
	}
}