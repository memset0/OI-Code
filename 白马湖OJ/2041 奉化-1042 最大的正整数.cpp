#include <bits/stdc++.h>
using namespace std;
int n;
string a[30];
bool cmp(string a, string b) {
	return a + b > b + a;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		cout << a[i];
	cout << endl;
	return 0;
}
