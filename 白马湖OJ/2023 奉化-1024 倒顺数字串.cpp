#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	cout << 1;
	for (int i = 2; i <= n; i++) 
		cout << " " << i;
	for (int i = n - 1; i >= 1; i--)
		cout << " " << i;
	cout << endl;
}
