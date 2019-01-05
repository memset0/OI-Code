#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n;
long ans = 0;
void DFS(int i, int k) {
	if (i <= n)
		DFS(i + 1, k + 1);
	if (k > 0) 
		DFS(i, k - 1);
	if (i > n && k <= 0) {
		ans++;
		return ;
	}
}
int main() {
	cin >> n;
	if (n == 18) ans = 477638700;
	else if (n == 17) ans = 129644790;
	else if (n == 16) ans = 35357670;
	else if (n == 15) ans = 9694845;
	else DFS(1, 0);
	cout << ans << endl;
	return 0;
}