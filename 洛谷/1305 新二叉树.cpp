#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
struct Leave {
	int left_child, right_child;
} T[maxn];
int n, is_s[maxn];
void build_tree(int x, int y, int z) {
	if (y != '*') {
		T[x - 'a'].left_child = y - 'a';
		is_s[y - 'a'] = 0;
	} else T[x - 'a'].left_child = -1;
	if (z != '*') {
		T[x - 'a'].right_child = z - 'a';
		is_s[z - 'a'] = 0;
	} else T[x - 'a'].right_child = -1;
}
void print(int n) {
	if (n == -1) return ;
	printf("%c", n + 'a');
	print(T[n].left_child);
	print(T[n].right_child);
}
int main() {
	memset(is_s, 1, sizeof(is_s));
//	cout << is_s[1];
	scanf("%d\n", &n);
	char x, y, z;
	for (int i = 1; i <= n; i++) {
		scanf("%c%c%c", &x, &y, &z);
		if (i != n) scanf("\n");
//		cout << x << " " << y << " " << z << endl;
		build_tree(x, y, z);
	}
	for (int i = 0; i < 26; i++)
		if (is_s[i]) {
			print(i);
			return 0;
		}
	return 0;
} 
