#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
const int maxl = 110;
int n, l, len = 0, k[maxn];
string a[maxn];
struct String {
	char c[maxl];
} s[maxn];
bool my_sort(int a, int b) {
	for (int i = 0; i < len; i++)
		if (s[a].c[i] != s[b].c[i]) return s[a].c[i] > s[b].c[i];
	return 0;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		k[i] = i;
		len = max(len, (int)a[i].length());
	}
	for (int i = 1; i <= n; i++) {
		l = a[i].length();
		for (int j = 0; j < len; j++) {
			if (j < len - l) s[i].c[j] = '0';
			else s[i].c[j] = a[i][j + l - len];
		}
	}
	sort(k + 1, k + n + 1, my_sort);
//	for (int i = 1; i <= n; i++)
//		cout << k[i] << " ";
//	puts("");
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < len; j++) 
//			cout << s[k[i]].c[j];
//		puts("");
//	}
	cout << k[1] << endl << a[k[1]] << endl;
	return 0;
}
